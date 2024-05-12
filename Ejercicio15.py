import multiprocessing as np

numero_de_procesadores = np.cpu_count()
for _ in range(numero_de_procesadores):
  print("Hola mundo")