import numpy as np
import os
from tflite_model_maker import configs
from tflite_model_maker import ExportFormat
from tflite_model_maker import model_spec
from tflite_model_maker import text_classifier
from tflite_model_maker.text_classifier import DataLoader

import tensorflow as tf
assert tf.__version__.startswith('2')
tf.get_logger().setLevel('ERROR')
data_file = tf.keras.utils.get_file(fname='comment-spam.csv', 
  origin='https://storage.googleapis.com/laurencemoroney-blog.appspot.com/lmblog_comments.csv', 
  extract=False)