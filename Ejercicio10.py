from multiprocessing import Process, Queue

def generar_serie(inicio, paso, num_terminos, output_queue):
    serie = []
    for i in range(num_terminos):
        valor = inicio + i * paso
        serie.append(valor)
    output_queue.put(serie)

if __name__ == "__main__":
    M = 4  
    N = 10  
    inicio = 2  
    paso = 2 

    procesos = []
    resultado = Queue()

    for i in range(M):
        proceso = Process(target=generar_serie, args=(inicio + i * N * paso, paso, N, resultado))
        proceso.start()
        procesos.append(proceso)

    for proceso in procesos:
        proceso.join()

    resultados = []
    while not resultado.empty():
        resultados.append(resultado.get())

    print("Generación de la serie en {} vectores con {} términos cada uno:".format(M, N))
    for i, serie in enumerate(resultados):
        print("Proceso {}: {}".format(i, serie))
