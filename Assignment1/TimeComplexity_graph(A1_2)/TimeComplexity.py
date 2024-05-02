'''
Measurements for size: 5000
Dynamic Array Insertion Time (size 5000): 0.021900 milliseconds
Dynamic Array Deletion Time (size 5000): 16.773100 milliseconds
Dynamic Array Access Time (size 5000): 6.545800 milliseconds
Linked List Insertion Time (size 5000): 42.541900 milliseconds
Linked List Deletion Time (size 5000): 0.333200 milliseconds
Linked List Access Time (size 5000): 0.017300 milliseconds

Measurements for size: 15000
Dynamic Array Insertion Time (size 15000): 0.062000 milliseconds
Dynamic Array Deletion Time (size 15000): 151.984500 milliseconds
Dynamic Array Access Time (size 15000): 104.695900 milliseconds
Linked List Insertion Time (size 15000): 544.563800 milliseconds
Linked List Deletion Time (size 15000): 1.011900 milliseconds
Linked List Access Time (size 15000): 0.045700 milliseconds

Measurements for size: 25000
Dynamic Array Insertion Time (size 25000): 0.088000 milliseconds
Dynamic Array Deletion Time (size 25000): 326.764400 milliseconds
Dynamic Array Access Time (size 25000): 142.362600 milliseconds
Linked List Insertion Time (size 25000): 1356.039300 milliseconds
Linked List Deletion Time (size 25000): 2.000000 milliseconds
Linked List Access Time (size 25000): 0.069400 milliseconds

Measurements for size: 35000
Dynamic Array Insertion Time (size 35000): 0.122700 milliseconds
Dynamic Array Deletion Time (size 35000): 628.676200 milliseconds
Dynamic Array Access Time (size 35000): 275.097700 milliseconds
Linked List Insertion Time (size 35000): 3090.379800 milliseconds
Linked List Deletion Time (size 35000): 2.436500 milliseconds
Linked List Access Time (size 35000): 0.097100 milliseconds
'''

import matplotlib.pyplot as plt
import numpy as np

# Measured execution times for dynamic array
dynamic_insertion_times = [0.0219, 0.062, 0.088, 0.1227]     # milliseconds
dynamic_deletion_times = [16.7731, 151.9845, 326.7644, 628.6762]  # milliseconds
dynamic_access_times = [6.5458, 104.6959, 142.3626, 275.0977]    # milliseconds

# Measured execution times for linked list
linked_insertion_times = [42.5419, 544.5638, 1356.0393, 3090.3798]  # milliseconds
linked_deletion_times = [0.3332, 1.0119, 2.0, 2.4365]             # milliseconds
linked_access_times = [0.0173, 0.0457, 0.0694, 0.0971]               # milliseconds

# Sizes of data structures
sizes = [5000, 15000, 25000, 35000]

# Generalized sizes
generalized_sizes = np.linspace(5000, 100000, 10000)

# Generalized time complexities
generalized_dynamic_insertion = np.polyfit(sizes, dynamic_insertion_times, 2)
generalized_dynamic_insertion_curve = np.polyval(generalized_dynamic_insertion, generalized_sizes)

generalized_linked_insertion = np.polyfit(sizes, linked_insertion_times, 2)
generalized_linked_insertion_curve = np.polyval(generalized_linked_insertion, generalized_sizes)

generalized_dynamic_deletion = np.polyfit(sizes, dynamic_deletion_times, 2)
generalized_dynamic_deletion_curve = np.polyval(generalized_dynamic_deletion, generalized_sizes)

generalized_linked_deletion = np.polyfit(sizes, linked_deletion_times, 2)
generalized_linked_deletion_curve = np.polyval(generalized_linked_deletion, generalized_sizes)

generalized_dynamic_access = np.polyfit(sizes, dynamic_access_times, 2)
generalized_dynamic_access_curve = np.polyval(generalized_dynamic_access, generalized_sizes)

generalized_linked_access = np.polyfit(sizes, linked_access_times, 2)
generalized_linked_access_curve = np.polyval(generalized_linked_access, generalized_sizes)

# Plotting the graphs
plt.figure(figsize=(12, 8))

# Insertion
plt.subplot(2, 2, 1)
plt.plot(sizes, dynamic_insertion_times, marker='o', label='Dynamic Array')
plt.plot(sizes, linked_insertion_times, marker='o', label='Linked List')
plt.title('Insertion Time Complexity')
plt.xlabel('Size of Data Structure')
plt.ylabel('Time (milliseconds)')
plt.yscale('log')  # Use logarithmic scale for y-axis
plt.legend()

# Deletion
plt.subplot(2, 2, 2)
plt.plot(sizes, dynamic_deletion_times, marker='o', label='Dynamic Array')
plt.plot(sizes, linked_deletion_times, marker='o', label='Linked List')
plt.title('Deletion Time Complexity')
plt.xlabel('Size of Data Structure')
plt.ylabel('Time (milliseconds)')
plt.yscale('log')  # Use logarithmic scale for y-axis
plt.legend()

# Access
plt.subplot(2, 2, 3)
plt.plot(sizes, dynamic_access_times, marker='o', label='Dynamic Array')
plt.plot(sizes, linked_access_times, marker='o', label='Linked List')
plt.title('Access Time Complexity')
plt.xlabel('Size of Data Structure')
plt.ylabel('Time (milliseconds)')
plt.yscale('log')  # Use logarithmic scale for y-axis
plt.legend()

# Generalized Time Complexity
plt.subplot(2, 2, 4)
plt.plot(generalized_sizes, generalized_dynamic_insertion_curve, label='Dynamic Array Insertion')
plt.plot(generalized_sizes, generalized_dynamic_deletion_curve, label='Dynamic Array Deletion')
plt.plot(generalized_sizes, generalized_dynamic_access_curve, label='Dynamic Array Access')
plt.plot(generalized_sizes, generalized_linked_insertion_curve, label='Linked List Insertion')
plt.plot(generalized_sizes, generalized_linked_deletion_curve, label='Linked List Deletion')
plt.plot(generalized_sizes, generalized_linked_access_curve, label='Linked List Access')
plt.title('Generalized Time Complexity')
plt.xlabel('Size of Data Structure')
plt.ylabel('Time (milliseconds)')
plt.yscale('log')  # Use logarithmic scale for y-axis
plt.legend()
#plt.ylim(0, max(max(dynamic_insertion_times), max(linked_insertion_times)) * 1.1)  # Adjust y-axis limit

plt.tight_layout()
plt.show()
