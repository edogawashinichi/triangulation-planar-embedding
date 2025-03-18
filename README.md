# Introduction
This project is aimed to draw a triangulation on a plane.\
The current tools, such as networkx, perform not well,
so this is why this project emerges.
# Input
A triangulation, that is a planar graph with $m=3n-6$,
where $m$($n$) is the number of edges(vertices) of the graph respectively.\
Currently users guarantee the input is a triangulation,
which will be verified by the project in the future.
The input json file is in the following format:
```json
{
  '0': ['1'],
  '1': ['0']
}
```
The keys are vertices of the graph, while the values are their neighbors.
# Output
The output json file is in the following format:
```json
{
  '0': [-1.0, -0.38], '1': [0.7, 0.15]
}
```
The keys are vertices of the graph,
while the values are their coordinates on the plane.\
This file can be visualized by using networkx in Python:
```python
# output_file is the output json file
infile = open(output_file, 'r')
js = infile.read()
dict_data = json.loads(js)
for key,value in dict_data.items():
    dict_data[key] = numpy.array(value)
infile.close()
# graph is the triangulation which shall be constructed with its edges
networkx.draw(graph, dict_data, with_labels=True)
```
