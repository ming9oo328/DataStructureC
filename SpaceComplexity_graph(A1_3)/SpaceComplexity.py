import numpy as np
import matplotlib.pyplot as plt

# Function to plot space complexities
def plot_space_complexities(sizes, dynamic_array_space, linked_list_space):
    fig, axes = plt.subplots(1, 2, figsize=(16, 6))

    # Plotting space complexities for given sizes
    axes[0].plot(sizes, dynamic_array_space, marker='o', label='Dynamic Array')
    axes[0].plot(sizes, linked_list_space, marker='o', label='Linked List')
    axes[0].set_title('Space Complexity Comparison')
    axes[0].set_xlabel('Number of Elements (n)')
    axes[0].set_ylabel('Space Complexity (bytes)')
    axes[0].set_xticks(sizes)
    axes[0].grid(True)
    axes[0].legend()

    # Plotting general trend
    n_values = np.linspace(5000, 100000, 1000)  # Generate n values from 5000 to 100000
    dynamic_array_general = n_values * 4 + 16  # General space complexity for dynamic arrays (linear growth)
    linked_list_general = n_values ** 2 * 3 + 40000  # General space complexity for linked lists (quadratic growth)

    axes[1].plot(n_values, dynamic_array_general, label='Dynamic Array')
    axes[1].plot(n_values, linked_list_general, label='Linked List')
    axes[1].set_title('General Trend of Space Complexity')
    axes[1].set_xlabel('Number of Elements (n)')
    axes[1].set_ylabel('Space Complexity (bytes)')
    axes[1].grid(True)
    axes[1].legend()

    plt.tight_layout()
    plt.show()

# Space complexities data
sizes = [5000, 15000, 25000, 35000]
dynamic_array_space = [20016, 60016, 100016, 140016]  # Space complexities for dynamic arrays
linked_list_space = [60000, 180000, 300000, 420000]  # Space complexities for linked lists

# Plotting
plot_space_complexities(sizes, dynamic_array_space, linked_list_space)
