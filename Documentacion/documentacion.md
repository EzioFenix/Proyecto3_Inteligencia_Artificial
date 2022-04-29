```yaml
Campus: Ciudad Universitaria
Facultad: Ingeniería
Materia : Inteligencia Artificial
Semestre: 2022-2
Equipo: 1
Clave: 0406
Participantes: 
	- Barrera Peña Víctor Miguel
	- Espino De Horta Joaquín Gustavo
	
Profesor: Dr. Ismael Everardo Barcenas Patiño
Título : Proyecto 
Subtítulo : Inferencia bayesiana
Fecha entrega: 05/05/2022

```

# Capítulo 0 Estructura del  repositorio

```yaml
.
├── Codigo
├── Diapositivas
├── Documentacion
├── LICENSE
├── Material_ayuda
└── README.md
```



# Definición del problema

## Clasificación Bayesiana

#  Solución

## Pseudocódigo

```python
inicio main():
    Datos= cargarDatos(nombre)

	Condiciones <= input()
	Cuestion	<= input()

	real 	probabilidad = 1.0, masProbable = 0.0
	cadena  Argumento = "No hay coincidencias", Objetivo, Regla 

	por_cada Objetivo en obten_coleccion(Cuestion) realiza:

		probabilidad = obten_Probabilidad(Datos,Objetivo)

		por_cada Regla en obten_coleccion(Condiciones) realiza:

			probabilidad = probabilidad * obten_Probabilidad(Datos,Objetivo,Regla)

		fin_bucle

		si (probabilidad > masProbable) entonces:

			mas probable <= probabilidad
			Argumento	 <= Objetivo

		fin_condicion

	fin_bucle

	imprimir(Argumento)

fin_main

inicio obten_Probabilidad(Datos,Objetivo):
	retorna	veces_En_Categoria(Datos,Objetivo) / (Datos.Altura - 1)
fin_obten_Probabilidad

inicio obten_Probabilidad(Datos,Objetivo,Regla):
	retorna	coincidencia(Datos,Objetivo,Regla) / veces_En_Categoria(Datos,Objetivo)
fin_obten_Probabilidad
```

# Experimentos

## Baja dificultad

### Problema 1

### Problema 2

### Problema 3

## Media dificultad

### Problema 1

### Problema 2

### Problema 3

## Alta dificultad

### Problema 1

### Problema 2

### Problema 3

## Sin solución

# Capítulo 1  Introducción 



# Capítulo 2 Desarrollo

## Idea de desarrollo del programa

## Casos de prueba

### Triviales (1 caso)

### Fáciles (3 casos)

### Media (3 casos)

### Difíciles ( 3 casos )

### Sin solución (1 caso)

### Código

## Explicación código

# Capítulo 3 Conclusión

## Barrera Peña Víctor Miguel

## Espino de Horta Joaquín Gustavo



# Anexo (teoría)

**Definición 1** (Experimentos aleatorios). Un experimento con diferentes resultados, incluso si es repetido en la misma manera, se llama un experimento aleatorio.

**Definición 2** (Espacio muestra). El conjunto de todos los posibles resultados de un experimento aleatorio, se llama el espacio muestra del experimento.
Ejemplo:
$$
\begin{align}
& S= \mathbb{R} + = \{x \in \mathbb{R}|x >0\} \\
& S= \{x \in N | 10 < x <20\} \\
& S=\{low,medium,light\} \\
& S= \{yes.not\}
\end{align}
$$

**Definición 3** (Espacio muestra discreto). Un espacio muestra es discreto si y sólo si, es contable.

Ejemplo:
$$
\begin{aligned}
&S=\{x \in \mathbb{N} \mid 10<x<20\} \\
&S=\{\text { low, medium,light }\} \\
&S=\{y e s, \text { not }\} \\
&S=\{x \in \mathbb{N} \mid \exists y \in \mathbb{N}: 2 y+1=x\} \\
&S=\{0,1\}^{\star}
\end{aligned}
$$
**Definición 4** (Espacio muestra continuo). Un espacio muestra S es continuo si y sólo si, existe una biyección $f: S \mapsto \mathbb{R}$ .

Ejemplos:
$$
\begin{aligned}
&S=\{x \in \mathbb{R} \mid 0<x<2\} \\
&S=\mathbb{R}^{+} \times \mathbb{R}^{+} \\
&S=\left\{x|x=| S^{\prime} \mid, S^{\prime} \subseteq \mathbb{N}\right\}
\end{aligned}
$$
**Definición 5** (Evento). Un evento $S$, es decir, $E \subseteq S$.

- La unión de dos eventos $E_1,E_2$ se define $E_1 \cup E_2=\{x|x \in E_1 or x \in E_2\}$.
- La intersección de dos eventos $E_1,E_2,$ se define $E_1 \cap E_2=\{x|x \in E_1 \text{and } x \in\}$.
- El complemento de un evento $E$ en el espacio muestral $S$ se define $E=\{x \in S | x \in E\}$.

**Ejemplos:** Considere el espacio muestra  $S={yy,yn,ny,nn}$. Los siguientes son eventos $S$.
$$
\begin{aligned}
&E_1=\{yy,yn,ny\}\\
& E_2=\{nn\}\\
& E_3=\empty 
\\
& E_4= S \\
& E_5 = \{yn,ny,nn\}
\end{aligned}
$$

$$
\begin{align}
 & E_1 \cup E_2 = S & E_1 \cap E_5=\{yn,ny\}  &  E^c 
\end{align}E_{1} \cup E_{2}=S, \quad E_{1} \cap E_{5}=\{y n, n y\}, \quad E_{1}^{c}=\{n n\}
$$
Mas ejemplos. Considere $ S =\mathbb{R}^+, E_{1}=\{x \mid 1 \leq x<10\} \text { y } E_{2}=\{x \mid 3<x<118\},$ entonces
$$
\begin{aligned}
E_{1} \cup E_{2} &=\{x \mid 1 \leq x<118\} \\
E_{1} \cap E_{2} &=\{x \mid 3<x<10\} \\
E_{1}^{c} &=\{x \mid x \geq 10\} \\
E_{1}^{c} \cap E_{2} &=\{x \mid 10 \leq x<118\}
\end{aligned}
$$
Algunas propiedades de los eventos.

Dos eventos $A$ y $B$ se dicen mutuamente exclusivos si y sólo si, su intersección de vacía, es decir, $A \cap B= \empty$
$$
\begin{aligned}
\left(E^{c}\right)^{c} &=E \\
(A \cup B) \cap C &=(A \cap C) \cup(B \cap C) \\
(A \cap B) \cup C &=(A \cup C) \cap(B \cup C) \\
(A \cup B)^{c} &=A^{c} \cap B^{c} \\
(A \cap B)^{c} &=A^{c} \cup B^{c} \\
A \cup B &=B \cup A \\
A \cap B &=B \cap A
\end{aligned}
$$

$$
\begin{aligned}
\left(E^{c}\right)^{c} &=E \\
(A \cup B) \cap C &=(A \cap C) \cup(B \cap C) \\
(A \cap B) \cup C &=(A \cup C) \cap(B \cup C) \\
(A \cup B)^{c} &=A^{c} \cap B^{c} \\
(A \cap B)^{c} &=A^{c} \cup B^{c} \\
A \cup B &=B \cup A \\
A \cap B &=B \cap A
\end{aligned}
$$

**Definición 6** (Probabilidad). En un espacio muestra discreto, la probabilidad
de un evento E, escrito P(E), es igual a la suma de las probabilidades de sus
resultados en E.

**Ejemplo.**

Un experimento aleatorio puede resultar en ${a,b,c,d}$ con probabilidades $0.1,0.3,0.5$ y $0.1$, respectivamente. Considere el evento A como $\{a,b\},B=\{b,c,d\}$ y $C={d}$. Entonces,
$$
\begin{aligned}
&P(A)=0.1+0.3=0.4 \\
&P(B)=0.3+0.5+0.1=0.9 \\
&P(C)=0.1
\end{aligned}
$$
También, $P\left(A^{c}\right)=0.6, P\left(B^{c}\right)=0.1, P\left(C^{c}\right)=0.9$. Más aún, debido a $A \cap B=$ $\{b\}$, entonces $P(A \cap B)=0.3$. Debido a $A \cup B=\{a, b, c, d\}, P(A \cup B)=$ $0.1+0.3+0.5+0.1=1$. Y debido a $A \cap C=\emptyset$, entonces $P(A \cap C)=0$.

**Definición 7** (Axiomas de la probabilidad). Considere los eventos $E,E_1$ y $E$ del espacio muestra $S$ de un experimento aleatorio.

- $P(S)=1$
- $0 \leq P(E) \leq 1$
- Si $E_{1} \cap E_{2}=\emptyset$, entonces $P\left(E_{1} \cup E_{2}\right)=P\left(E_{1}\right)+P\left(E_{2}\right)$

Algunas propiedades.
$$
P(\emptyset)=0 \quad P\left(E^{c}\right)=1-P(E) \quad \text { Si } E_{1} \subseteq E_{2}, \text { entonces } P\left(E_{1}\right) \leq P\left(E_{2}\right)
$$

# Ejercicios

## Problema 1

Suponga que las placas de los vehículos están compuestas inicialmente por tres dígitos (0−9), seguidas de tres letras (A−Z). Calcule la probabilidad de una determinada placa.

## Problema 2

Un mensaje puede seguir diferentes rutas a través de una red de servidores. En el primer paso, el mensaje puede llegar a cinco servidores, a partir de cada uno de estos servidores, el mensaje puede llegar a cinco servidores m´as, desde los cuales puede acceder a otros cuatro servidores.

- Calcule la cantidad de rutas.
- Si todas las rutas son igualmente probables, calcule la probabilidad de que el mensaje llegue a alguno de los cuatro servidores del tercer bloque.

## Demuestre lo siguiente

$$
P(\empty)= 0
$$

$$
\begin{align}
	S^c&=\empty  &\text{ Definimos el conjunto}\\
	P(S \cup S^c)&=P(S)+P(S^c)-P(S \cap S^c) & \text{ Usamos la prpiedad} \\
	P(S \cup S^c)&= 1 + P(S^c) -  0  & \text{ Sustituimos}\\
	P(S \cup S^c)&= 1 &\text{ Decladamos una propieda} \\
	1-1 &=P(S^c)  & \text{ Sustituimos lo anterios} \\
	0 &=P(S^c) \\
	P(S^c) &= 0 \\
	\therefore P(\empty) &= 0
\end{align}
$$




$$
P(E^c)=1-P(E)
$$

$$
\text { Para cualquier evento } A, P(A)+P\left(A^{\prime}\right)=1 \text {, a partir de la cual } P(A)=1-P\left(A^{\prime}\right) \text {. }
$$

Comprobación En el axioma 3 , sea  $k=2, A_{1}=A$ y $A_{2}=A^{\prime}$  . Como por definición de $A^{\prime}, A \cup A^{\prime}=\mathcal{S}$ en tanto $A$ y $A^{\prime}$ sean eventos disjuntos, $1=P(\mathcal{S})=P\left(A \cup A^{\prime}\right)=$  $P(A)+P\left(A^{\prime}\right)$


$$
\text{Si } E_1 \subseteq E_2 \text{ entonces } P(E_1) \leq P(E_2)
$$

- Si tienen los mismos elementos, entonces la probabilidad de obtener un evento $E_1,E_2$, es la misma, pero y si $E_2$ Tiene un elemento más que $E_2$ su  probabilidad aumenta, esto se puede demostrar por ordinales de conjuntos.

$$
\frac{\#E_1}{Total} \leq \frac{\#E_2}{Total}
$$

$E_1,E_2$ es el número de elementos a favor.

# Mas ejemplos

## Problema 1

Una mezcla química es preparada correctamente por el 25% de los técnicos de un laboratorio, 70% de los técnicos la preparan con un error mínimo, y 5% con un error mayor. 

- Si un técnico es elegido aleatoriamente, ¿Cuál es la probabilidad de que prepare la mezcla sin error alguno?

$$
P(E)=25\%
$$



- Calcule la probabilidad de que el técnico la prepare con cualquier tipo de error.

$$
P(E)=70\% + 5\%=75\%
$$



## Problema 2

Considere las emisiones de tres fabricas clasificadas por su calidad. De la primera fábrica 22 muestras de emisiones cumplen con el mínimo, y 8 no lo hacen; 25 cumplen con el mínimo y 5 no, en el caso de la segunda fábrica; en cuanto a la tercera, 30 cumplen y 10 no. Considere A denota el evento de las muestras de emisiones de la primera fábrica, y B como el evento de una muestra cumple con el mínimo. Calcule las siguientes probabilidades.
$$
P(A) \quad P(B) \quad P\left(A^{c}\right) \quad P(A \cap B) \quad P(A \cup B) \quad P\left(A^{c} \cup B\right)
$$
**Solución:**
$$
\begin{align}
P(A) &= \frac{22+8}{100} = 0.3\\
P(B) &= \frac{22+25+30}{100}\\
P\left(A^{c}\right)&= \frac{70}{100} \\
P(A \cap B)&= \frac{22}{100}\\
P(A \cup B) &= \frac{22+25+30}{100} \\
P\left(A^{c} \cup B\right)& = \frac{70+8}{100}
\end{align}
$$
**Definición 8** (regla de la adición).
$$
P(A \cup B)= P(A) +(B) - P(A )ls
$$

**Definición** (Regla de la adición).

​	
$$
P(A \cup B) = P(A) + P(B) - P(A \cap B)
$$
**Ejemplo** 

Considere la tabla abajo con el historial de producción de 949 semiconductores. Suponga que un semiconductor es elegido aleatoriamente. Considere $M$ denota el evento de que el semiconductor contiene niveles altos de contaminación. C es el evento cuando el semiconductor se encuentra en el centro de una herramienta de pulverización.
$$
P(H \cup C)= P(H) + P(C) - P(H \cap C)=\frac{1}{940} (358+626 -112)= \frac{872}{940}
$$


![](C:\Users\DELL\Documents\Proyectos\Proyecto3_Inteligencia_Artificial\Documentacion\img\table1.png)

**Ejemplo:** En el mismo contexto del ejemplo anterior, considere $E_1$ el evento de que un semiconductor contiene 4 o más partículas contaminantes, $E2$ es el evento de que un semiconductor se encuentra en la orilla de la herramienta.
$$
P(E_1 \cap E_2) = P(E_1) + P(E_2) - P(E_1 \cap E_2) =
$$


![]()

**Ejercicios**

Si P(A) = 0.3, P(B) = 0.2, y P(A ∩ B) = 0.1, determine las siguientes probabilidades:
$$
\begin{array}{lll}
P\left(A^{c}\right) & P(A \cup B) & P\left(A^{c} \cap B\right) \\
P\left(A \cap B^{c}\right) & P\left((A \cup B)^{c}\right) & P\left(A^{c} \cup B\right)
\end{array}
$$

**Definición 9 **(Probabilidad condicional) . La proba

# 8

- Calcule la probabilidad de que el inspector detecte un objeto defecuso

# 9

**Ejemplo.** Considere la siguiente base de datos.

| #    | Usuario | Género | Calificación |
| ---- | ------- | ------ | ------------ |
| 1    | F       | Terror | 1            |
| 2    | M       | Acción | 3            |
| 3    | F       | Drama  | 2            |
| 4    | M       | Drama  | 2            |
| 5    | F       | Acción | 2            |
| 6    | M       | Terror | 3            |
| 7    | F       | Terror | 3            |
| 8    | M       | Drama  | 1            |
| 9    | F       | Acción | 2            |

Calcule la calificación que le pondría un usuario $M$ a una película de Drama.
$$
\begin{aligned}
&P(1) P(\mathrm{M} \mid 1) P(\text { Drama } \mid 1)=2 / 9 * 1 / 2 * 1 / 2=1 / 18 \\
&P(2) P(\mathrm{M} \mid 2) P(\text { Drama } \mid 2)=4 / 9 * 1 / 4 * 1 / 2=1 / 18 \\
&P(3) P(\mathrm{M} \mid 3) P(\text { Drama } \mid 3)=1 / 3 * 2 / 3 * 0=0
\end{aligned}
$$
Entonces el usuario califica con $2$  o $1$ a la película de Drama.

## Ejercicio

Implemente un algoritmo para el modelo de clasificación Bayesiana.

# Clase de hoy

**Ejemplo.** Considere la siguiente base de datos.

| Usuario | Género | Calificación |
| ------- | ------ | ------------ |
| F       | Terror | 1            |
| M       | Acción | 3            |
| F       | Drama  | 2            |
| M       | Drama  | 2            |
| F       | Acción | 2            |
| M       | Terror | 3            |
|         |        |              |
|         |        |              |
|         |        |              |



## Ejemplo

## Ejercicios

Considere la siguiente base de datos.

| #    | Productora | Usuario | Género | Calificación |
| ---- | ---------- | ------- | ------ | ------------ |
| 1    | Universal  | F       | Terror | 1            |
| 2    | Universal  | M       | Acción | 3            |
| 3    | Warner     | F       | Drama  | 2            |
| 4    | Disney     | M       | Drama  | 2            |
| 5    | Warner     | F       | Acción | 2            |
| 6    | Disney     | M       | Terror | 3            |
| 7    | Universal  | F       | Terror | 3            |
| 8    | Disney     | M       | Drama  | 1            |
| 9    | Warney     | F       | Acción | 2            |
| 10   | Warner     | M       | Acción | 1            |
| 11   | Disney     | F       | Drama  | 2            |
| 12   | Universal  | F       | Terror | 3            |
| 13   | Warner     | F       | Terror | 3            |
| 14   | Disney     | M       | Acción | 2            |
| 15   | Universal  | M       | Drama  | 1            |

Calcule la calificación que otorgará un usuario $F$ a una película de Acción producida Warner.
$$
P(1) \cdot P(F|1) \cdot P(A|1) \cdot P(W | 1) \\
=\frac{4}{15} \cdot \frac{1}{4} \cdot \frac{1}{4} \cdot \frac{1}{4} = \frac{4}{960}=0.0041\overline{6}
$$

$$
P(2) \cdot P(F|2) \cdot P(A|2) \cdot P(W | 2) \\
=\frac{6}{15} \cdot \frac{4}{6} \cdot \frac{3}{6} \cdot \frac{3}{6} = \frac{216}{3240}=0.0666\overline{6}
$$

$$
P(3) \cdot P(F|3) \cdot P(A|3) \cdot P(W | 3) \\
=\frac{5}{15} \cdot \frac{3}{5} \cdot \frac{1}{5} \cdot \frac{1}{5} = \frac{15}{1,875}=0.0026\overline{6}
$$

## Ejercicio

| #    | Director   | Productora | Usuario | Género | Calificación |
| ---- | ---------- | ---------- | ------- | ------ | ------------ |
| 1    | Hnos coen  | Universal  | F       | Terror | 1            |
| 2    | Del tor    | Universal  | M       | Acción | 3            |
| 3    | Bañuel     | Warner     | F       | Drama  | 2            |
| 4    | Bañuel     | Disney     | M       | Drama  | 2            |
| 5    | Hnos. Coen | Warner     | F       | Acción | 2            |
| 6    | Del toro   | Disney     | M       | Terror | 3            |
| 7    | Del toro   | Universal  | F       | Terror | 3            |
| 8    | Hnos. Coen | Disney     | M       | Drama  | 1            |
| 9    | Bañuel     | Warner     | F       | Acción | 2            |
| 10   | Del toro   | Warner     | M       | Acción | 1            |
| 11   | Bañuel     | Disney     | F       | Drama  | 2            |
| 12   | Hnos. Coen | Universal  | F       | Terror | 3            |
| 13   | Hnos. Coen | Warner     | F       | Terror | 3            |
| 14   | Del Toro   | Disney     | M       | Acción | 2            |
| 15   | Bañuel     | Universal  | M       | Drama  | 1            |
| 16   | Bañuel     | Warner     | M       | Acción | 1            |
| 17   | Del Toro   | Warner     | F       | Acción | 2            |
| 18   | Bañuel     | Disney     | M       | Drama  | 3            |
| 19   | Hnos. Coen | Universal  | M       | Terror | 1            |
| 20   | Hnos. Coen | Warner     | F       | Terror | 1            |
| 21   | Del Toro   | Disney     | F       | Acción | 2            |
| 22   | Bañuel     | Uiversal   | M       | Drama  | 3            |

$$
P(1) \cdot P(M|1) \cdot P(Terror|1) \cdot P(Universal | 1) \cdot P(Bañuel | 1) \\
=\frac{7}{22} \cdot \frac{5}{7} \cdot \frac{3}{7} \cdot \frac{3}{7} \cdot \frac{2}{7} = \frac{45}{3773}=0.0119268
$$

$$
P(2) \cdot P(M|2) \cdot P(Terror|2) \cdot P(Universal | 2) \cdot P(Bañuel | 2) \\
=\frac{8}{22} \cdot \frac{2}{7} \cdot 0 \cdots =0
$$

$$
P(3) \cdot P(M|3) \cdot P(Terror|3) \cdot P(Universal | 3) \cdot P(Bañuel | 3) \\
=\frac{7}{22} \cdot \frac{4}{7} \cdot \frac{4}{7} \cdot \frac{4}{7} \cdot \frac{2}{7} = \frac{896}{52,822}=0.0169626
$$
