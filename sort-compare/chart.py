import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = pd.read_csv('./answer.csv')
data.plot(x = 'Test number', y = ['Quick Sort Time','C++ Sort Time', 'Heap Sort Time', 'Merge Sort Time'], 
          kind = 'bar', figsize=(40,10), width = 0.75)
plt.xlabel('Test number')
plt.ylabel('Time execute (ms)')
plt.legend(loc="upper left")
ind = np.arange(len(data['Test number']))
for i, a, b, c, d in zip(ind, data['Quick Sort Time'], data['C++ Sort Time'], data['Heap Sort Time'], data['Merge Sort Time']):
  plt.text(i - 0.27, a + 10, str(a), color='b', horizontalalignment='center')
  plt.text(i - 0.09, b + 10, str(b), color='orange', horizontalalignment='center')
  plt.text(i + 0.09, c + 10, str(c), color='g', horizontalalignment='center')
  plt.text(i + 0.27, d + 10, str(d), color='r', horizontalalignment='center')

plt.savefig('time execute.png')
plt.show()