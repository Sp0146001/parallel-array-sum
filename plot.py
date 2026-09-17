import matplotlib.pyplot as plt

data = [
    (1, 453),
    (2, 240),
    (4, 159),
    (8, 125),
    (16, 113),
    (32, 113),
    (64, 111),
    (128, 111),
    (256, 114),
    (512, 117),
    (1024, 120)
]

threads = [str(x[0]) for x in data]
medians = [x[1] for x in data]

plt.figure(figsize=(12, 6))

plt.bar(threads, medians, color='#4C72B0', edgecolor='black', alpha=0.8, width=0.7)

plt.xlabel('Количество потоков', fontsize=12)
plt.ylabel('Время выполнения, мс (медиана)', fontsize=12)
plt.title('Зависимость времени суммирования массива от числа потоков', fontsize=14)

for i, v in enumerate(medians):
    plt.text(i, v + 5, str(v), ha='center', va='bottom', fontsize=10, fontweight='bold')

plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.tight_layout()

plt.savefig('graph.png', dpi=300)
