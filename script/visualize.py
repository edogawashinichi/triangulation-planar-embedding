#!/usr/bin/python3

import sys
import json
import networkx as nx
import numpy as np
import matplotlib.pyplot as plt
import ast # WARNING: JSONDecodeError Expecting property name enclosed in double quotes

# file_name = "xx.json"
def load_graph(file_name):
  print("load_graph: " + file_name)
  with open(file_name, "r") as f:
    file_str = f.read()
    #file_str = str(ast.literal_eval(file_str))
    graph_dict = json.loads(file_str)
    print("graph dict:")
    print(graph_dict)
    return graph_dict

def create_graph(graph_dict):
  graph = nx.Graph()
  for v in graph_dict.keys():
    graph.add_node(v)
  for key,value in graph_dict.items():
    for v in value:
      graph.add_edge(key, v)
  return graph

# file_name = "xx.json"
def load_position(file_name):
  with open(file_name, "r") as f:
    file_str = f.read()
    #file_str = str(ast.literal_eval(file_str))
    position_dict = json.loads(file_str)
    for key,value in position_dict.items():
      position_dict[key] = np.array(value)
    print("position dict:")
    print(position_dict)
    return position_dict

# file_name = "xx.png"
def draw_embedding(graph, position_dict, file_name):
  nx.draw(graph, position_dict, with_labels=True)
  plt.savefig(fname=file_name)

if __name__ == '__main__':
  input_dir = "../data/input/"
  output_dir = "../data/output/"
  graph_file = "triangle.json"
  position_file = "demo_triangle.json"
  embedding_file = "triangle.png"
  if len(sys.argv) == 2:
    graph_file = sys.argv[1] + ".json"
    position_file = sys.argv[1] + ".json"
    embedding_file = sys.argv[1] + ".png"
  elif len(sys.argv) == 3:
    graph_file = sys.argv[1] + ".json"
    position_file = sys.argv[2] + "_" + sys.argv[1] + ".json"
    embedding_file = sys.argv[2] + "_" + sys.argv[1] + ".png"
  graph_path = input_dir + graph_file
  position_path = output_dir + position_file
  embedding_path = output_dir + embedding_file
  draw_embedding(create_graph(load_graph(graph_path)), load_position(position_path), embedding_path)
