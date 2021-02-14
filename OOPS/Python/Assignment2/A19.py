from sklearn.metrics import confusion_matrix , accuracy_score
from sklearn.neural_network import MLPClassifier
import matplotlib.pyplot as plt
import numpy as np
import gzip
import random
from sklearn.metrics import roc_auc_score
import time
from sklearn.neighbors import KNeighborsClassifier

f = gzip.open('train-images-idx3-ubyte.gz', 'r')

image_size = 28
num_images = 60000

f.read(16)
buf = f.read(image_size * image_size * num_images)
data = np.frombuffer(buf, dtype=np.uint8).astype(np.float32)
train_data = data.reshape(num_images, image_size * image_size)


# image = np.asarray(data[random.choice(list(range(num_images)))])
# plt.imshow(image)
# plt.show()

f = gzip.open('train-labels-idx1-ubyte.gz', 'r')

f.read(8)
buf = f.read( num_images )
data = np.frombuffer(buf, dtype=np.uint8).astype(np.float32)
train_labels = data.reshape( num_images )

# print(train_labels[random.choice(list(range(num_images)))])

f = gzip.open('t10k-labels-idx1-ubyte.gz', 'r')

test_num_images = 10000
f.read(8)
buf = f.read( test_num_images )
data = np.frombuffer(buf, dtype=np.uint8).astype(np.float32)
test_labels = data.reshape( test_num_images )

# print(train_labels[random.choice(list(range(test_num_images)))])

f = gzip.open('t10k-images-idx3-ubyte.gz', 'r')
f.read(16)
buf = f.read(image_size * image_size * test_num_images)
data = np.frombuffer(buf, dtype=np.uint8).astype(np.float32)
test_data = data.reshape(test_num_images, image_size * image_size)

def train_knn():
    st = time.time()
    classifier = KNeighborsClassifier(n_neighbors=7)
    classifier.fit(train_data, train_labels)
    pred = classifier.predict(test_data)
    en = time.time() - st
    return pred , en

def train_3_layer_nn():
    st = time.time()
    classifier = MLPClassifier( hidden_layer_sizes=(500,300) )
    classifier.fit(train_data , train_labels)
    pred = classifier.predict(test_data)
    en = time.time() - st
    return pred ,en



method ="KNN"
pred, en = train_knn()

# method = "3 Layer Neural Network"
# pred ,en = train_3_layer_nn()


cm = confusion_matrix(test_labels, pred)

print(cm)
# print("7 neighbours")
print("Algorithm :" , method)
print( 'accuracy  : ' ,  accuracy_score( test_labels  , pred) )
# print( 'ROC score' , roc_auc_score( test_labels , pred))
# print( "Time taken : " , en / 60 , " minutes.")
