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

threads = [x[0] for x in data]
medians = [x[1] for x in data]

plt.figure(figsize=(10, 6))

plt.plot(threads, medians, marker='o', linewidth=2, markersize=6, color='#4C72B0')

plt.xlabel('Количество потоков')
plt.ylabel('Время выполнения, мс (медиана)')
plt.title('Зависимость времени суммирования массива от числа потоков')

plt.xscale('log', base=2)
plt.xticks(threads, threads)

plt.grid(True, linestyle='--', alpha=0.7)
plt.tight_layout()

plt.savefig('graph2.png', dpi=300)
