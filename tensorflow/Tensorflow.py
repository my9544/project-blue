import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data

# Dataset loading
mnist = input_data.read_data_sets("./samples/MNIST_data/", one_hot=True) #데이터를 자동으로 다운로드하고 설치

# Set up model
x = tf.placeholder(tf.float32, [None, 784]) # [none, 784] 형태의 부정소숫점으로 이루어진 2차원 텐서로 표현 
W = tf.Variable(tf.zeros([784, 10])) #TensorFlow의 상호작용하는 작업 그래프들간에 유지되는 변경 가능한 텐서
b = tf.Variable(tf.zeros([10]))
y = tf.nn.softmax(tf.matmul(x, W) + b) #모델을 구현 

y_ = tf.placeholder(tf.float32, [None, 10]) #정답을 입력하기 위한 새 placeholder

cross_entropy = -tf.reduce_sum(y_*tf.log(y)) #y의 각 원소 로그값 계산 그리고 텐서의 모든 원소를 더함 
train_step = tf.train.GradientDescentOptimizer(0.01).minimize(cross_entropy) #경사 하강법(gradient descent) 알고리즘을 이용하여 교차 엔트로피를 최소화

# Session
init = tf.initialize_all_variables() #변수 초기화 

sess = tf.Session() #세션에서 모델을 시작하고 작업 시작
sess.run(init)

# Learning
for i in range(1000): #1000번 실행 
  batch_xs, batch_ys = mnist.train.next_batch(100) # 학습 세트로부터 100개의 무작위 데이터들의 일괄 처리(batch)들을 가져옵니다. placeholders를 대체하기 위한 일괄 처리 데이터에 train_step 피딩을 실행 
  sess.run(train_step, feed_dict={x: batch_xs, y_: batch_ys})

# Validation
correct_prediction = tf.equal(tf.argmax(y,1), tf.argmax(y_,1)) # 예측이 실제와 맞는지 확인 
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32)) #부정소숫점으로 캐스팅한 후 평균값 계산 

# Result should be approximately 91%.
print(sess.run(accuracy, feed_dict={x: mnist.test.images, y_: mnist.test.labels})) #정확도 확인 
