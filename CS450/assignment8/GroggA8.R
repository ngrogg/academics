library(igraph)
library(linkcomm)

# igraph function to load graphml file into memory
# Graphml is an xml file
# Load a graph and print some basic features
LoadGraph <- function(filePath, format){
	print(filePath)
	graph <-read_graph(filePath, format=format)
	summary(graph)
	return(graph)
}

# Sorting is painful, this makes it less so
TopValues <-function(graph, values, n-5) {
	return(v(graph)[sort.list(values,decreasing-TRUE)[1:n]])
}

# Calculate a bunch of vertex metrics and attach them to the graph supplied
BoatLoadOfMetrics <-function(result) {
  
  #i_degree: Unweighted degree
  V(result)$i_degree  <- degree(result, mode="all")
  #i_strength: Weighted degree
  V(result)$i_strength <- strength(result, mode="all")
  
  decUnweighted <- eigen_centrality(result, directed=FALSE, weights=NA)
  #i_eigen_cent_u: Unweighted Eigenvector Centrality
  decWeighted <- eigen_centrality(result, directed=FALSE)
  
  V(result)$i_eigen_cent_u <- decUnweighted$vector
  
  V(result)$i_eigen_cent_w <- decWeighted$vector
  
  #V(result)$authority <- authority_score(result)$vector
  #i_hub_u: Unweighted Hub scores (see note below)
  V(result)$i_hub_u <- hub_score(result, weights=NULL)$vector
  
  #i_hub_w: Weighted Hub scores
  V(result)$i_hub_w <- hub_score(result, weights=E(result)$weight)$vector
  
  #i_page_rank_u: Unweighted Page Rank
  V(result)$i_page_rank_u <- page_rank(result, directed=FALSE)$vector
  
  #i_page_rank_w: Weighted Page Rank
  V(result)$i_page_rank_w <- page_rank(result, directed=FALSE, weights = E(result)$weight)$vector
  
  #i_between_u: Unweighted Betweenness centrality
  V(result)$i_between_u <- betweenness(result, ,weights = NULL, normalized=TRUE )
  
  #i_between_w: Weighted Betweenness centrality
  V(result)$i_between_w <- betweenness(result, weights=E(result)$weight , normalized=TRUE)
  
  #i_closeness_u: Unweighted Closeness centrality
  V(result)$i_closeness_u <- closeness(result, normalized=TRUE, weights=NULL)
  
  #i_closeness_w: Weighted Closeness centrality
  V(result)$i_closeness_w <- closeness(result, normalized=TRUE, weights=E(result)$weight)
  
  return (result)
}

#Creates a binned historgram of the data supplied (expectes output of degree or nonzero_degree)
binned_histogram <- function(data, base=2) {
  numbins <- ceiling(log(length(data), base))
  breakpoints <- exp(seq(log(min(data)), log(max(data)), length.out=numbins+1))
  return(hist(data, breaks=breakpoints, plot=FALSE))
}

#Removes the 0 value from the degree calculation
nonzero_degrees <- function(g, mode="total") {
  d <- degree(g, mode=mode) 
  return(d[d != 0])
}

#Helps determine the regime of the network
RegimeAnalysis <- function(graph){
  averageDegree <- mean(degree(graph))
  logN = log(vcount(graph))
  print(paste("Average Degree: ", averageDegree))
  print(paste("ln(N): ", logN))
  if (averageDegree < 1) print("Subcritical Regime - No giant component, Clusters are trees")
  else if (averageDegree == 1) print("Critical Point - No giant component, Clusters may contain loops")
  else if (averageDegree > logN) print("Connected Regime - Single giant component, no isolated nodes or clusters, giant component may have loops")
  else print("Supercritical Regime - Single giant component, small clusters are trees, giant component has loops")
}


# Corrects for degree data for plotting.  Degree starts with 1 index but degree_distribution starts with 0 index.
# This adjusts degree for plotting.
degree_domain <- function(g, mode="total") {
  return(0:max(degree(g, mode=mode)))
}

#Generates a plot for the preferrential attachment model supplied
PlotPaModel <- function(model, model.fitPowerLaw, title, mode="total") {
  # Same for the preferrential attachment model 
  plot(degree_domain(model, mode=mode), degree_distribution(model, mode=mode, cumulative=TRUE),  main=title, log="xy", xlab="k", ylab="p(k)")
  legend("topright", bty="n", 
         c(paste("xmin =", model.fitPowerLaw$xmin),
           paste("max degree =", max(degree(model, mode=mode))), 
           paste("gamma = ", round(model.fitPowerLaw$alpha, digits=2)),
           paste("KS stat = ", round(model.fitPowerLaw$KS.stat, digits=3)),
           paste("KS p = ", round(model.fitPowerLaw$KS.p, digits=3))
         ))
}



# Set your working directory
# Cannot change the working directory error, somethings mistyped
# I don't think I need this. I'll fill it out, but I probably won't use it
#setwd("")
SetName <- "Brain Network"
filePath <- "100307_connectome_scale33.graphml"
format <- "graphml"

graph <- LoadGraph(filePath, format)

# Unique to this data set
E(graph)$conductivity <- E(graph)$fiber_length_mean / E(graph)$number_of_fibers

V(graph)$dn_name
V(graph)$dn_fsname

# Checks if brains have more inter-hemisphere connectivity than others
assortativity(graph, as.factor(V(graph)%dn_hemisphere))

table(degree(graph))

# Creates a plot to show distribution
plot(table(degree(graph)))

# Shows the probability that a randomly selected node will have a particular degree.
degree_distribution(graph)

plot(degree_distribution(graph))

table(degree_distribution(graph))

hist(E(graph)$conductivity, breaks=length(unique(E(graph)$conductivity)))

graph.bh <- binned_histogram(nonzero_degrees(graph))

plot(graph.bh$mids, graph.bh$density, main=SetName, xlab="k", ylab="p(k)", log="xy")
