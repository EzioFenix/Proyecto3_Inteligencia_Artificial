

from cv2 import line
from random import randint
import sys

def listaIndiceAleatorio(n:int)->list:
    indice_ordenado=[i for i in range(0,n,1)]
    indice_desordenado=[]
    intevaloAleatorio=n-1 # Cambia este valor, a mayor numero más revuelto, tiene que ser menor que n
    maxi=n-intevaloAleatorio
    

    # Generamos el indice aleatorio---------------------------------------

    for i in reversed(range(0,n,1)) :
        indice_aleatorio=randint(i-intevaloAleatorio,i)
        indice_desordenado.append(indice_ordenado.pop(indice_aleatorio))


        if len(indice_ordenado)<intevaloAleatorio:
            intevaloAleatorio-=1

    return indice_desordenado

def aleatorizacion(dimensiones,lineas):

    x,y=dimensiones.strip().split(",")
    x=int(x)
    dimension=int(y) -1
    indiceAleatorio=listaIndiceAleatorio(dimension)
    archivoReordenado=["" for i in range(0,dimension,1)]
    
    for i in range(0,dimension,1):
        archivoReordenado[i]=lineas[indiceAleatorio[i]]
    return archivoReordenado

def guardar_Archivo(nombre:str,dimensiones:str,cabecera:str,lineas:list):
    nombre,tipo=nombre.strip().split(".")
    nombre=nombre + "_precision" + "." +tipo

    with open(nombre,"w") as f:
        f.write(dimensiones)
        f.write(cabecera)
        f.writelines(lineas)

        



def main():
    try:
        nombre=sys.argv[1]
        with open(nombre, encoding = 'utf-8') as f:
        # perform file operations
            # Dimension x,y
            dimensiones= f.readline()
            cabecera=f.readline()
            lineas=f.readlines()

            # El ultimo no tiene salto de linea por ello se lo agregamos
            lineas[-1]+='\n'

            # Revolvemos el archivo
            lineas=aleatorizacion(dimensiones,lineas)

            #El ultimo elemento no tiene que tener salto de linea
            lineas[-1]=lineas[-1].strip()

            # Guardamos el nuevo archivo de precision
            guardar_Archivo(nombre,dimensiones,cabecera,lineas)
    finally:
        f.close()

if __name__ == "__main__":
    main()
    