'''
The Dataset I chose was the banknote authentication data set
Since it's numeric, and the same size as the Iris dataset 

https://archive.ics.uci.edu/ml/datasets/banknote+authentication

Yes, I'm aware of what a cop out that is...

This data set is supposed to predict whether something is true or false
Where true represents real money and false represents fake money

My understanding of this program is that it's a Neural Network
that takes in a training file to build a model, and a test file 
to test that model. These trainings are done in batches
'''

# iris_nn.py
# PyTorch 0.4.1 Anaconda3 5.2.0 (Python 3.6.5)
import numpy as np
import torch as T
import pytest

# -----------------------------------------------------------
# This def takes data into batches for training
class Batch:
  def __init__(self, num_items, bat_size, seed=0):
    self.num_items = num_items; self.bat_size = bat_size
    self.rnd = np.random.RandomState(seed)

  # Funtion to queue up the next batch of data for training
  def next_batch(self):
    return self.rnd.choice(self.num_items, self.bat_size,
      replace=False)

# -----------------------------------------------------------
# This def is the Neural Network
class Net(T.nn.Module):
  def __init__(self):
    super(Net, self).__init__()
    # My hiddenLayerSize variable, use self so it can be reassigned
    self.hiddenLayerSize = 100
    # How many states into how many hidden layers?
    self.fc1 = T.nn.Linear(4, self.hiddenLayerSize)
    T.nn.init.xavier_uniform_(self.fc1.weight)  # glorot
    T.nn.init.zeros_(self.fc1.bias)
    # How many hidden layers into how many outputs?
    self.fc2 = T.nn.Linear(self.hiddenLayerSize, 2)
    T.nn.init.xavier_uniform_(self.fc2.weight)
    T.nn.init.zeros_(self.fc2.bias)

  def forward(self, x):
    z = T.tanh(self.fc1(x))
    z = self.fc2(z)  # see CrossEntropyLoss() below
    return z

# -----------------------------------------------------------
# This def is used to check model accuracy
def accuracy(model, data_x, data_y):
  X = T.Tensor(data_x)
  Y = T.LongTensor(data_y)
  oupt = model(X)
  (_, arg_maxs) = T.max(oupt.data, dim=1)
  num_correct = T.sum(Y==arg_maxs)
  # Accuracy is calculated 
  acc = (num_correct * 100.0 / len(data_y))
  return acc.item()

# -----------------------------------------------------------
# Def to combine the model definition and training into one
def train(learningRate, hiddenLayerSize, maxIterations, train_x, train_y):
  net = Net()
  # Assign user assigned values to function
  net.hiddenLayerSize = hiddenLayerSize
  lrn_rate = learningRate; b_size = 12
  max_i = maxIterations; n_items = len(train_x)
  loss_func = T.nn.CrossEntropyLoss()  # applies softmax()
  optimizer = T.optim.SGD(net.parameters(), lr=lrn_rate)
  # Sets batch parameters
  batcher = Batch(num_items=n_items, bat_size=b_size)

  # After values have been assigned, start training the data
  print("Starting training")
  # Create string based on learningRate, hiddenLayerSize and maxIterations
  firstLine = ("Learning Rate: " + str(learningRate) + "\n" + 
               "Hidden Layer Size: " + str(hiddenLayerSize) + "\n" +
               "Max Iterations: " + str(maxIterations) + "\n")

  # Open text file to append to
  with open("output.txt", "a") as myFile:
    # Write that first line to the output file, this helps log what was run
    myFile.write(firstLine)

    # For loop to train model
    for i in range(0, max_i):
      if i > 0 and i % (max_i/10) == 0:
        # Print out what iteration the program is on
        print("iteration = %4d" % i, end="")

        # Print out the total loss
        print("  loss = %7.4f" % loss_obj.item(), end="")
        acc = accuracy(net, train_x, train_y)

        # Print out the accuracy of the model
        print("  accuracy = %0.2f%%" % acc)

        # Create string from data
        outputString = ("iteration = " + str(i) +
                        " loss = " + str(loss_obj.item()) +
                        " accuracy = " + str(acc) + "\n")
        # Append string to file
        myFile.write(outputString)
      # Load up the next batch for training
      curr_bat = batcher.next_batch()
      
      # Load x and y data into X and Y for training
      X = T.Tensor(train_x[curr_bat])
      Y = T.LongTensor(train_y[curr_bat])

      # Uses the learn rate the affect the Neural Network's steps
      optimizer.zero_grad()
      oupt = net(X)
      # Calculates loss
      loss_obj = loss_func(oupt, Y)
      loss_obj.backward()
      # Increment the learn rate
      optimizer.step()
  # Once training is done, return the network
  return net

# -----------------------------------------------------------
def main():
  # 0. get started
  print("\nBegin Iris Dataset with PyTorch demo \n")
  T.manual_seed(1);  np.random.seed(1)

  # 1. load data
  print("Loading banknote data into memory \n")
  train_file = "banknote_train.txt"
  test_file = "banknote_test.txt"

  # Feed comma delimited values into numpy array(s) for training
  train_x = np.loadtxt(train_file, usecols=range(0,4),
    delimiter=",",  skiprows=0, dtype=np.float32)
  train_y = np.loadtxt(train_file, usecols=[4],
    delimiter=",", skiprows=0, dtype=np.float32)
  test_x = np.loadtxt(test_file, usecols=range(0,4),
    delimiter=",",  skiprows=0, dtype=np.float32)
  test_y = np.loadtxt(test_file, usecols=[4],
    delimiter=",", skiprows=0, dtype=np.float32)

  # User inputs values for learningRate, hiddenLayerSize, and maxIterations
  # I'm aware these are some horrible variable names...
  print("Enter float value for learningRate")
  lR = float(input())
  print("Enter int value for hiddenLayerSize")
  hLS = int(input())
  print("Enter int size for maxIterations")
  mI = int(input())

  # learningRate, hiddenLayerSize, maxIterations, train_x, train_y
  net = train(lR, hLS, mI, train_x, train_y)
  print("Training complete \n")

  # 4. evaluate model
  net = net.eval()  # set eval mode
  acc = accuracy(net, test_x, test_y)

  # Output accuracy, and log to output file
  with open("output.txt", "a") as myFile:
    print("Accuracy on test data = %0.2f%%" % acc) 
    myFile.write("Accuracy on test data = " + acc + "\n")

  # 5. save model
  # The model is output to the file as it runs. This step is unncessary

# -----------------------------------------------------------
  # 6. make a prediction

  # This one should return close to 1
  unk = np.array([[-2.9138,-9.4711,9.7668,-0.60216]], dtype=np.float32)

  unk = T.tensor(unk)  # to Tensor
  logits = net(unk)  # values do not sum to 1.0
  probs_t = T.softmax(logits, dim=1)  # as Tensor
  probs = probs_t.detach().numpy()    # to numpy array
  print("\nSetting inputs to:")
  for x in unk[0]: print("%0.1f " % x, end="")

  # Output result and append result to text file
  with open("output.txt", "a") as myFile:
    # Write predictions to file
    myFile.write("0,1 likelihood \n")

    # Output predictions to screen
    print("\nPredicted likelihood: (0,1)")

    # Go through probabilities, output them and write them to file
    for p in probs[0]: 
      print("%0.4f " % p, end="")
      myFile.write(str(p) + " ")

    # Line breaks so different runs can be distinguished
    myFile.write("\n\n")

  print("\n\nEnd Iris demo")
if __name__ == "__main__":
  main()
