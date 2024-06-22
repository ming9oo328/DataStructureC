'''
Dynamic Array Data Space (size 5000, elements 5000): 20000 bytes
Dynamic Array Space Complexity (size 5000, elements 5000): 20016 bytes
Linked List Data Space (size 5000, elements 5000): 20000 bytes
Linked List Space Complexity (size 5000, elements 5000): 60000 bytes

Dynamic Array Data Space (size 15000, elements 15000): 60000 bytes
Dynamic Array Space Complexity (size 15000, elements 15000): 60016 bytes
Linked List Data Space (size 15000, elements 15000): 60000 bytes
Linked List Space Complexity (size 15000, elements 15000): 180000 bytes

Dynamic Array Data Space (size 25000, elements 25000): 100000 bytes
Dynamic Array Space Complexity (size 25000, elements 25000): 100016 bytes
Linked List Data Space (size 25000, elements 25000): 100000 bytes
Linked List Space Complexity (size 25000, elements 25000): 300000 bytes

Dynamic Array Data Space (size 35000, elements 35000): 140000 bytes
Dynamic Array Space Complexity (size 35000, elements 35000): 140016 bytes
Linked List Data Space (size 35000, elements 35000): 140000 bytes
Linked List Space Complexity (size 35000, elements 35000): 420000 bytes
'''

import numpy as np
import matplotlib.pyplot as plt

# Data
sizes = [5000, 15000, 25000, 35000]
dynamic_array_data_space = [20000, 60000, 100000, 140000]
dynamic_array_space_complexity = [20016, 60016, 100016, 140016]
linked_list_data_space = [20000, 60000, 100000, 140000]
linked_list_space_complexity = [60000, 180000, 300000, 420000]

# Plotting
plt.figure(figsize=(15, 5))  # 그래프 크기 조정

plt.subplot(1, 3, 1)  # 1행 3열 중 첫 번째 서브플롯
plt.plot(sizes, linked_list_data_space, label='Linked List Data Space', marker='o', color='orange')
plt.plot(sizes, dynamic_array_data_space, label='Dynamic Array Data Space', marker='o', linestyle='--', color='blue')
plt.title('Data Space Analysis')
plt.xlabel('Size of elements')
plt.ylabel('Space (bytes)')
plt.legend()
plt.grid(True)
plt.ticklabel_format(style='plain')  # 지수 표기 비활성화
# Add data values next to each point
for i, size in enumerate(sizes):
    plt.text(sizes[i], dynamic_array_data_space[i] + 3000, f'{dynamic_array_data_space[i]:.2f}', ha='center', va='bottom', fontsize=8, color='blue')
    plt.text(sizes[i], linked_list_data_space[i] - 3000, f'{linked_list_data_space[i]:.2f}', ha='center', va='top', fontsize=8, color='orange')

plt.subplot(1, 3, 2)  # 1행 3열 중 두 번째 서브플롯
plt.plot(sizes, linked_list_space_complexity, label='Linked List Space Complexity', marker='o', linestyle='--', color='orange')
plt.plot(sizes, dynamic_array_space_complexity, label='Dynamic Array Space Complexity', marker='o', color='blue')
plt.title('Space Complexity Analysis')
plt.xlabel('Size of elements')
plt.ylabel('Space (bytes)')
plt.legend()
plt.grid(True)
plt.ticklabel_format(style='plain')  # 지수 표기 비활성화
# Add data values next to each point
for i, size in enumerate(sizes):
    plt.text(sizes[i], dynamic_array_space_complexity[i] + 3000, f'{dynamic_array_space_complexity[i]:.2f}', ha='center', va='bottom', fontsize=8, color='blue')
    plt.text(sizes[i], linked_list_space_complexity[i] - 3000, f'{linked_list_space_complexity[i]:.2f}', ha='center', va='top', fontsize=8, color='orange')

def generate_generalized_data(size):
    # Generalized values based on the size
    dynamic_array_data_space_generalized = size * 4
    dynamic_array_space_complexity_generalized = size * 4 + 16
    linked_list_data_space_generalized = size * 4
    linked_list_space_complexity_generalized = size * 12
    
    return (dynamic_array_data_space_generalized, dynamic_array_space_complexity_generalized,
            linked_list_data_space_generalized, linked_list_space_complexity_generalized)

# Generalized sizes
generalized_sizes = np.linspace(10000, 50000, 4)

# Initialize lists to store generalized values
generalized_dynamic_array_data_space = []
generalized_dynamic_array_space_complexity = []
generalized_linked_list_data_space = []
generalized_linked_list_space_complexity = []

# Generate generalized data
for size in generalized_sizes:
    dadata, dacomp, lldata, llcomp = generate_generalized_data(size)
    generalized_dynamic_array_data_space.append(dadata)
    generalized_dynamic_array_space_complexity.append(dacomp)
    generalized_linked_list_data_space.append(lldata)
    generalized_linked_list_space_complexity.append(llcomp)

plt.subplot(1, 3, 3)  # 1행 3열 중 세 번째 서브플롯
# Plotting
plt.plot(generalized_sizes, generalized_dynamic_array_data_space, label='Generalized Dynamic Array Data Space', color='blue')
plt.plot(generalized_sizes, generalized_linked_list_data_space, label='Generalized Linked List Data Space', linestyle='dashed', color='orange')
plt.plot(generalized_sizes, generalized_linked_list_space_complexity, label='Generalized Linked List Space Complexity', marker='o', linestyle='dotted', color='green')
plt.plot(generalized_sizes, generalized_dynamic_array_space_complexity, label='Generalized Dynamic Array Space Complexity', marker='o', linestyle='dotted', color='red')
plt.title('Generalized Space Complexity Analysis')
plt.xlabel('Size of elements')
plt.ylabel('Space (bytes)')
plt.legend()
plt.grid(True)
plt.ticklabel_format(style='plain')  # 지수 표기 비활성화
# Add data values next to each point
for i, size in enumerate(generalized_sizes):
    plt.text(size, generalized_dynamic_array_data_space[i] - 3000, f'{generalized_dynamic_array_data_space[i]:.2f}', ha='center', va='top', fontsize=8, color='blue')
    plt.text(generalized_sizes[i] + 5000, generalized_linked_list_data_space[i], f'{generalized_linked_list_data_space[i]:.2f}', ha='left', va='center', fontsize=8, color='orange')
    plt.text(generalized_sizes[i], generalized_linked_list_space_complexity[i], f'{generalized_linked_list_space_complexity[i]:.2f}', ha='right', va='center', fontsize=8, color='green')
    plt.text(size, generalized_dynamic_array_space_complexity[i] + 3000, f'{generalized_dynamic_array_space_complexity[i]:.2f}', ha='center', va='bottom', fontsize=8, color='red')

plt.tight_layout()  # 서브플롯 간 간격 조정
plt.show()
