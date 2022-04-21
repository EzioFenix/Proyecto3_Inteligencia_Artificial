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

# Definición del problema

## Clasificación Bayesiana

#  

# Solución

## Pseudocódigo

## Explicación

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

Comprobación En el axioma 3 , sea $k=2, A_{1}=A$ y $A_{2}=A^{\prime}$. Como por definición de $A^{\prime}, A \cup A^{\prime}=\mathcal{S}$ en tanto $A$ y $A^{\prime}$ sean eventos disjuntos, $1=P(\mathcal{S})=P\left(A \cup A^{\prime}\right)=$  $P(A)+P\left(A^{\prime}\right)$


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
