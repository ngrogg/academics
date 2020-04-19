library(igraph)
library(linkcomm)

#load a graph and print some basic features
LoadGraph <- function(filePath, format)
{
  print(filePath)
  graph <-read_graph(filePath, format=format)
  summary(graph)
  return (graph)
}

#sorting is painful, this makes it less so
TopValues <- function(graph, values, n=5) {
  return(V(graph)[sort.list(values, decreasing=TRUE)[1:n]])
}

#calculate a bunch of vertex metrics and attach them to the graph supplied
BoatLoadOfMetrics <- function(result) {
  
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

setwd("C:/Users/administrator/OneDrive/GradSchool/human connectome project/pit_group_connectomes") # Set to yours 
SetName <- "Brain Network"
filePath <-"100307_connectome_scale33.graphml"
format <- "graphml"

graph <- LoadGraph(filePath, format)

#can't find the paper i got this from, need to check the math on it
E(graph)$conductivity <- E(graph)$fiber_length_mean / E(graph)$number_of_fibers

#do some brains have more inter-hemisphere connectivity than others?
#this one is around 90%
assortativity(graph, as.factor(V(graph)$dn_hemisphere))


table(degree(graph))

#kinda looks like a normal distribution
plot(table(degree(graph)))
#probability that a randomly selected node will have a particular degree.
#notice the gaps
degree_distribution(graph)

#looks like a normal distribution with heavy variance
plot(degree_distribution(graph))


#because of the gaps, what are the actual realistic probabilities?
table(degree_distribution(graph))

# assuming conductivity is calculated correctly,
# what is the frequency of it?
# looks like many nodes have high conductivity (high resistance)
# while few nodes have very low conductivity, long tail
hist(E(graph)$conductivity, breaks=length(unique(E(graph)$conductivity)))

graph.bh <- binned_histogram(nonzero_degrees(graph))

#looks like an inverted normal distribution with a high tail
#does not look like a power law distribution
plot(graph.bh$mids, graph.bh$density, main=SetName, xlab="k", ylab="p(k)", log="xy")

#max distance between nodes (5) on 83 nodes and 618 edges (scale 33 real)
diameter(graph)

#average shortest path between verticies
mean_distance(graph)

#551 are neighbors, 1281 with path 2, 1128 with path 3, 331 with path 4, 30 with path 5, 2% are unconnected
distance_table(graph)

# fully connected may have loops.  Note, Graph of our mind 2016 said loops were deleted!
RegimeAnalysis(graph)

#.54% chance that two two nieghbors connect to eachother
# this makes sense given the shortest path numbers
# Q! - I wonder what it is in a given hemisphere and if hemisphere numbers differ...
# Q! - how many communities are there?
transitivity(graph, type="global")

#Not that helpful, we know that all nodes but one are connected in some way, and that one is probably a matter of resolution not actual connectivity.
#Q! how do metrics change with higher resolution?  
components(graph)

#lets see how it compares to a random graph
graph.gnm <- sample_gnm(vcount(graph), ecount(graph))

#wow, huge transitivity difference! 19%
transitivity(graph.gnm)

#components size is the same basically, fully connected
components(graph.gnm)$csize

assortativity_degree(graph, directed=FALSE)
assortativity_degree(graph.gnm, directed=FALSE)

degree(graph.gnm)
degree_distribution(graph.gnm)
#even shorter distances!  still interested in a single hemisphere analysis
mean_distance(graph.gnm)
diameter(graph.gnm)

#interesting, its basically the same but inverted and mirrored
#spoke to Ramon, evolutionary cliques form with bridges
#results in low path high connectivity and follows transitivity
graph.gnm.bh <- binned_histogram(nonzero_degrees(graph.gnm))
plot(graph.gnm.bh$mids, graph.gnm.bh$density, main=SetName, xlab = "k", ylab="p(k)", log="xy")


#keeping_degseq preserves degree distribution
#niter number of rewiring trials to perform
#increasing niter seems to reduce transitivity and increase diamter and avg distance
#Seems as though the transitivity is very different from random graphs, while other properties can be accounted
#for by random processes
graph.rewired <- rewire(graph, with=keeping_degseq(niter=ecount(graph) * 100))
transitivity(graph.rewired)
mean_distance(graph.rewired)
diameter(graph.rewired)

#as promised, the degree distribution looks very similar
graph.rewired.bh <- binned_histogram(nonzero_degrees(graph.rewired))
plot(graph.rewired.bh$mids, graph.rewired.bh$density, main=SetName, xlab = "k", ylab="p(k)", log="xy")

#infomap found four groups
graph.infomap <- cluster_infomap(graph)


#nei the neighborhood within with the vertices of the lattice will be connected
#p rewiring probability
#transitivity increases with neighborhood value
#distance and diameter drop considerably
graph.sw <- sample_smallworld(1, vcount(graph), 21, 0.15)
transitivity(graph.sw)
mean_distance(graph.sw)
diameter(graph.sw)

#reverts to random degree distribution
graph.sw.bh <- binned_histogram(nonzero_degrees(graph.sw))
plot(graph.sw.bh$mids, graph.sw.bh$density, main=SetName, xlab = "k", ylab="p(k)", log="xy")


#this needs more work, i need to review power law distributions
#Q! this looks similar to a power law distribution with no tail as a curve but I need to review the metrics 
# and what they mean.  I thought fit_power_law would provide a metric that said how close or far it is
# to a power law distribution
# had a ks.stat of 0.0896 and p of 0.97 so this could have been a power law distribution
# what does that mean again?  Week 6 Assignment 9
# Readings: Barabasi Ch. 5 and Barabasi Ch. 6, excluding 6.4 (read for concepts even if you don't understand the math)
# Optional Readings: Easley & Kleinberg 18.3-18.6 for conceptual presentation; Newman 14.1-14.4 for mathematical analysis.

(m <- round(ecount(graph)/vcount(graph)))
z <- 1 # changes max degree, smaller z is larger hub
power <- 1.075 #higher power means higher degree but gamma is not changing
graph.pa <- sample_pa(vcount(graph), directed=TRUE, zero.appeal=z, m=m)
summary(graph)
summary(graph.pa)
?fit_power_law
graph.fitPowerLaw <- fit_power_law(degree(graph), implementation="plfit")
graph.pa.fitPowerLaw <- fit_power_law(degree(graph.pa), implementation="plfit")
PlotPaModel(graph, graph.fitPowerLaw, paste(SetName, " PA power = ", power))
PlotPaModel(graph.pa, graph.pa.fitPowerLaw, paste(SetName, " PA power = ", power))

#next, we should see some interesting things in centrality  week 7 assignment 10
E(graph)$weight <- E(graph)$number_of_fibers

#most of the metrics are looking for a column called weights...soo lets add one
#not convinced on my conductivity and number of fibers is more interesting to me than length
graph <- BoatLoadOfMetrics(graph)
summary(graph)

#DEGREE - connections
# number of connections vs weighted by number of fibers are very very different.
# therefore the number of connections to different vertices is an important feature
# as is the number of fibers between those connections.
TopValues(graph, V(graph)$i_degree)$dn_name #i_degree: Unweighted degree
TopValues(graph, V(graph)$i_strength)$dn_name#i_strength: Weighted degree

#Eigen Centrality - strong connectors connected to strong connectors are higher
TopValues(graph, V(graph)$i_eigen_cent_u)$dn_name #i_eigen_cent_u: Unweighted Eigenvector Centrality
TopValues(graph, V(graph)$i_eigen_cent_w)$dn_name #i_eigen_cent_w: Weighted Eigenvector Centrality

#HUB - Kleinberg's hub cetnrality.  authority_score
TopValues(graph, V(graph)$i_hub_u)$dn_name #i_hub_u: Unweighted Hub scores (see note below)
TopValues(graph, V(graph)$i_hub_w)$dn_name  #i_hub_w: Weighted Hub scores

#Page Rank - Google guys
TopValues(graph, V(graph)$i_page_rank_u)$dn_name  #i_page_rank_u: Unweighted Page Rank
TopValues(graph, V(graph)$i_page_rank_w)$dn_name #i_page_rank_w: Weighted Page Rank

#Betweenness - finding those that are central to shortest distances
TopValues(graph, V(graph)$i_between_u)$dn_name #i_between_u: Unweighted Betweenness centrality
TopValues(graph, V(graph)$i_between_w)$dn_name #i_between_w: Weighted Betweenness centrality

#looking at these a very interesting thing is missing, the brain stem.
#my understanding is that the brain stem is central to connecting to the body which means that connection is not a huge part of brain centrality!
#need to find out which nodes connect left/right hemispheres.  Probably some of those in the hub results
# interesting that left/right areas with same name don't share values.  Shows the topological differences of those areas (i.e. if Left/Right Hippocampus both had strong  
# hub scores we might infer that they are central to their hemisphere but that isn't the case
# different regions are key to the centrality of the different hemispheres)
#Closeness - Closeness centrality measures how many steps is required to access every other vertex from a given vertex.
TopValues(graph, V(graph)$i_closeness_u)$dn_name #i_closeness_u: Unweighted Closeness centrality
TopValues(graph, V(graph)$i_closeness_w)$dn_name #i_closeness_w: Weighted Closeness centrality
