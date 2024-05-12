from multiprocessing import Pool, cpu_count

def fibonacci(n):
    if n <= 1:
        return n
    else:
        a, b = 0, 1
        for _ in range(n - 1):
            a, b = b, a + b
        return b

def calcular_terminos_de_fibonacci(terminos):
    return [fibonacci(termino) for termino in terminos]

if __name__ == "__main__":
    total_terminos = 1000
    numero_de_procesadores = cpu_count()

    terminos_por_procesador = total_terminos // numero_de_procesadores
    lista_de_terminos = [range(i * terminos_por_procesador, (i + 1) * terminos_por_procesador) for i in range(numero_de_procesadores)]
    lista_de_terminos[-1] = list(lista_de_terminos[-1]) + list(range(numero_de_procesadores * terminos_por_procesador, total_terminos))

    with Pool(processes = numero_de_procesadores) as pool:
        resultados = pool.map(calcular_terminos_de_fibonacci, lista_de_terminos)

    secuencia_de_fibonacci = []
    for resultado in resultados:
        secuencia_de_fibonacci.extend(resultado)

    print("Términos de la secuencia de Fibonacci calculados:")
    for i, termino in enumerate(secuencia_de_fibonacci):
        print(f"Término {i + 1}: {termino}")
