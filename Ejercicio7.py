import multiprocessing as np
import math

def calcular_pi(inicial, final):
  vector_pi = []
  for i in range(inicial, final):
    if (i == 0):
      continue
    termino = (1/(i**2))
    vector_pi.append(termino)
  return (vector_pi)

if __name__ == "__main__":
  limite_pi = 1000000
  parametros_pi = [ ((i*limite_pi), (limite_pi*(i+1))) for i in range(np.cpu_count())]
  pool_pi = Pool()
  resultado_pi = pool_pi.starmap(calcular_pi, parametros_pi)
  pi = math.sqrt(6 * sum(sum(resultado_pi, [])))
  print("Valor estimado de PI:", pi)