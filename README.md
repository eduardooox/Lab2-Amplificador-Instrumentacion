# Laboratorio 2 — Amplificador de instrumentación biomédico

Proyecto del curso **Instrumentación Biomédica I**, Escuela Profesional de Ingeniería Biomédica, Facultad de Ingeniería Electrónica y Eléctrica, Universidad Nacional Mayor de San Marcos (UNMSM).

**Grupo:** 05 / L12 (lunes, 20:00–22:00 h).  
**Fecha de la práctica:** 21 de septiembre de 2026.  
**Docente:** Dra. María Elisia Armas Alvarado.

## Integrantes

- Juan Carlos José Alfaro Flores.
- Andrea Betzabe Girao Pebes.
- Rosa Regina Manrique Sandoval.
- Eduardo Manuel Yanayaco Cochachin.

## Descripción y alcance

El proyecto caracteriza un amplificador de instrumentación de tres amplificadores operacionales implementado con un TL084N. Se estudian la variación de la ganancia diferencial con la resistencia Rg y la respuesta ante una señal aplicada en modo común.

Además, se desarrolla una etapa de acondicionamiento con una referencia de 2.50 V bufferizada mediante un LM324N y un nodo resistivo que permite adaptar la salida a la entrada analógica de un Arduino Mega 2560.

Las etapas A, B y C se documentan mediante mediciones del montaje físico. Según la indicación recibida durante la sesión, la referencia bufferizada, el nodo sumador y la adquisición de la etapa D se validaron mediante simulación en Proteus. Las señales utilizadas son de prueba; no corresponden a registros adquiridos de una persona.

## Objetivos

- Verificar el montaje y el offset de salida del amplificador de instrumentación.
- Medir la ganancia diferencial para diferentes valores de Rg y compararla con el modelo teórico.
- Medir la respuesta en modo común e interpretar las limitaciones del cálculo de CMRR.
- Simular la referencia bufferizada y el acondicionamiento para el ADC.
- Digitalizar la señal de prueba y visualizar los datos recibidos por comunicación serial.

## Organización de los archivos

La siguiente organización propone nombres uniformes para publicar el proyecto. Antes de entregar el repositorio, ajustar los nombres a los archivos reales y retirar las filas de recursos que no se hayan incluido.

| Ruta propuesta | Contenido |
| --- | --- |
| `README.md` | Descripción, configuración e instrucciones de reproducción. |
| `codigo/Lab02_Instrumentacion/Lab02_Instrumentacion.ino` | Código fuente completo de generación y adquisición. |
| `simulacion/Lab02_Instrumentacion.pdsprj` | Proyecto editable de Proteus. |
| `simulacion/firmware/` | Archivo compilado que utiliza el modelo del microcontrolador, por ejemplo `.hex`. |
| `simulacion/` | Archivos asociados necesarios para abrir el proyecto, si corresponde. |
| `datos/` | Mediciones experimentales y muestras seriales originales, si se conservaron. |
| `evidencias/` | Fotografías del montaje y capturas de simulación. |
| `documentacion/` | Esquemático exportado e informe final, si se incluyen. |

El archivo `.ino` debe conservarse dentro de una carpeta con el mismo nombre base, como se muestra en la ruta propuesta. El firmware compilado complementa al código fuente y no lo sustituye.

## Recursos y programas

### Montaje experimental

- TL084N y red resistiva del amplificador de instrumentación.
- Potenciómetro para el ajuste de Rg.
- Fuente de banco dual de aproximadamente ±9 V.
- Generador de señal de prueba, filtro RC y divisor atenuador.
- Protoboard, cables y capacitores de desacople.
- Multímetro y osciloscopio.

### Etapa D simulada

- Modelo de Arduino Mega 2560.
- TL084N y LM324N.
- Divisor de referencia de 10 kΩ / 10 kΩ, alimentado con 5 V.
- Dos resistencias de 10 kΩ para el nodo sumador.
- Virtual Terminal y osciloscopio virtual de Proteus.

### Software

| Recurso | Configuración |
| --- | --- |
| Arduino IDE | Registrar la versión con la que se compiló el código. |
| Paquete de placas | Arduino AVR Boards; registrar la versión utilizada. |
| Placa de compilación | Arduino Mega or Mega 2560. |
| Procesador | ATmega2560. |
| Proteus | Registrar la versión con la que se guardó y ejecutó el proyecto. |
| Modelos adicionales | Indicar nombre, versión y fuente de instalación si el proyecto los requiere. |

No se presupone que los modelos adicionales estén incluidos en toda instalación de Proteus. Si el proyecto utiliza una librería externa para Arduino, documentar su instalación y cualquier dependencia necesaria.

## Configuración del código

Los siguientes parámetros corresponden al código mostrado en el informe:

| Parámetro | Valor |
| --- | --- |
| Pin de salida PWM | 2. |
| Frecuencia de la envolvente sinusoidal de prueba | 2 Hz. |
| Intervalo programado de actualización del valor PWM | 2 ms. |
| Entrada analógica del nodo sumador | A0. |
| Intervalo programado de adquisición | 10 ms. |
| Frecuencia de adquisición nominal | 100 muestras/s. |
| Velocidad de comunicación serial | 9600 baudios. |
| Resolución del ADC del Mega | 10 bits. |
| Conversión empleada en el código | `voltaje = lecturaRaw * (5.0 / 1023.0)`. |

Los 2 Hz corresponden a la envolvente sinusoidal que modifica el ciclo de trabajo, no a la frecuencia portadora del PWM. El intervalo de 10 ms define una tasa nominal: el tiempo de ejecución de las tareas puede introducir diferencias respecto al intervalo efectivo.

## Reproducción de la simulación

1. Descargar el repositorio completo o clonarlo, conservando la organización de sus carpetas.
2. Instalar la versión de Proteus indicada y los modelos adicionales que requiera el proyecto.
3. Abrir el archivo `.ino` en Arduino IDE.
4. Seleccionar la placa Arduino Mega or Mega 2560 y el procesador ATmega2560.
5. Verificar que los parámetros del programa coincidan con la tabla de configuración.
6. Compilar el programa. Si es necesario generar el firmware, utilizar **Sketch / Programa → Export Compiled Binary / Exportar binarios compilados**. El archivo exportado debe corresponder a la placa seleccionada.
7. Abrir el proyecto `.pdsprj` en Proteus.
8. Revisar la propiedad **Program File** del modelo que ejecuta el firmware y seleccionar el archivo compilado incluido o recién generado. Si aparece una ruta de otro equipo, reemplazarla por la ruta local correcta.
9. Comprobar la salida PWM del pin 2, la conexión del nodo sumador a A0 y la referencia común de GND entre las etapas.
10. Configurar el Virtual Terminal para que coincida con la comunicación de 9600 baudios y ejecutar la simulación.
11. Observar las muestras seriales y los trazos del osciloscopio virtual. El Virtual Terminal muestra datos numéricos; para visualizar una curva es necesario usar una herramienta de representación gráfica.
12. Si se reconstruye la gráfica a partir de muestras consecutivas y del intervalo nominal, documentar que el eje temporal se obtiene como `t_ms = indice_muestra * 10`. Si se dispone de marcas de tiempo reales, utilizar esas marcas en lugar de asumir intervalos exactos.

Antes de publicar la entrega, comprobar la apertura y ejecución del proyecto desde una copia ubicada en otra carpeta. Esta comprobación permite detectar archivos asociados ausentes y rutas de firmware que solo funcionan en el equipo de origen.

## Acondicionamiento y niveles de tensión

El divisor de 10 kΩ / 10 kΩ genera una referencia de aproximadamente 2.50 V a partir de la alimentación de 5 V. El LM324N se utiliza como seguidor para bufferizar esta referencia.

El nodo que conecta dos resistencias iguales —una a la referencia y otra a la salida del amplificador— realiza un promedio resistivo. Considerando una carga de alta impedancia:

`V_nodo ≈ (V_AI + V_ref) / 2`

Por tanto, si la salida del amplificador se encuentra centrada alrededor de 0 V, el nodo queda aproximadamente centrado en 1.25 V. La referencia del buffer y el nivel central del nodo sumador son distintos. El rango de este último debe comprobarse para la amplitud y ganancia utilizadas.

## Resultados e interpretación

- Se registró un offset de salida de aproximadamente 6 mV con ambas entradas conectadas a GND.
- La ganancia diferencial aumentó al reducir Rg.
- Para Rg = 5990 Ω se obtuvo una ganancia experimental aproximada de 4.45 y una teórica de 4.34.
- Para Rg = 1990 Ω se obtuvo una ganancia experimental aproximada de 11.48 y una teórica de 11.05.
- La condición de Rg ≈ 1.8 Ω se reportó con salida limitada y no permite validar una ganancia diferencial lineal mediante el cociente registrado.
- En modo común se registraron 2.72 Vpp de entrada y 28.8 mVpp de salida, con una relación aproximada de 0.01059.
- La referencia bufferizada de la etapa D se verificó en simulación con un valor de 2.50 V.

El informe contiene un cálculo de CMRR de 87.78 dB basado en el cociente de amplitudes obtenido para la condición de salida limitada. Ese valor debe identificarse como aparente y no como un CMRR validado en régimen lineal. Una validación requiere medir la ganancia diferencial sin recorte y la ganancia en modo común con el mismo ajuste de Rg y condiciones comparables.

El intervalo exacto del nodo sumador y de la gráfica reconstruida debe documentarse a partir de las muestras originales, haciendo coincidir los datos, las tablas y las figuras del informe final.

## Datos y evidencias

Publicar los registros originales disponibles para permitir la revisión de los resultados:

- Mediciones de Rg, Vin(pp) y Vout(pp), con unidades identificadas.
- Registros de entrada y salida en modo común.
- Verificación de la referencia y del nodo sumador en simulación.
- Muestras seriales utilizadas para reconstruir la gráfica.
- Fotografías y capturas identificadas según su etapa.

Si no se conservaron las muestras originales, indicarlo y conservar la gráfica como evidencia visual; no presentar datos reconstruidos manualmente como registros originales.

## Referencias del trabajo

- Guía de Laboratorio N.° 2 del curso Instrumentación Biomédica I, UNMSM.
- Informe de Laboratorio N.° 2 elaborado por el grupo.
- Hojas de datos del TL084 y LM324 de Texas Instruments, en las revisiones citadas en el informe.

## Créditos

Trabajo académico desarrollado por los integrantes indicados al inicio. Las fotografías, los esquemáticos propios y los resultados corresponden a las etapas documentadas en el informe. Las imágenes o documentación de terceros deben conservar su atribución a la fuente correspondiente.
