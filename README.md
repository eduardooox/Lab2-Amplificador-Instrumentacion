# Laboratorio 2 — Amplificador de instrumentación biomédico

Repositorio del proyecto de **Instrumentación Biomédica I**, Escuela Profesional de Ingeniería Biomédica, Universidad Nacional Mayor de San Marcos (UNMSM).

## Descripción

El proyecto comprende la caracterización de un amplificador de instrumentación implementado con el TL084N y el acondicionamiento de su salida para la adquisición mediante Arduino Mega 2560.

La verificación inicial, la caracterización de ganancia y la prueba de modo común se realizaron en el montaje físico. La etapa de referencia bufferizada con LM324N, el nodo sumador y la adquisición digital se validaron mediante simulación en Proteus.

## Integrantes

- Juan Carlos José Alfaro Flores.
- Andrea Betzabe Girao Pebes.
- Rosa Regina Manrique Sandoval.
- Eduardo Manuel Yanayaco Cochachin.

## Organización del repositorio

| Ubicación | Contenido |
| --- | --- |
| `README.md` | Descripción, configuración y pasos de ejecución. |
| `codigo/` | Programas Arduino. Cada archivo `.ino` se conserva dentro de una carpeta con su mismo nombre base. |
| `simulacion/` | Proyecto de Proteus y archivos asociados necesarios para abrirlo. |
| `simulacion/firmware/` | Archivo compilado utilizado por el modelo del microcontrolador, por ejemplo `.hex`. |
| `datos/` | Mediciones y muestras de adquisición disponibles en formatos `.csv`, `.xlsx` o `.txt`. |

Ejemplo de ubicación del código: `codigo/Lab02_Instrumentacion/Lab02_Instrumentacion.ino`. Si existen programas independientes, cada uno debe conservarse en su propia carpeta.

## Requisitos

- Arduino IDE con el paquete Arduino AVR Boards.
- Placa de compilación: Arduino Mega or Mega 2560.
- Procesador: ATmega2560.
- Proteus con los modelos necesarios para el circuito.

## Configuración del programa

Los parámetros corresponden al programa de generación y adquisición del proyecto:

| Parámetro | Configuración |
| --- | --- |
| Salida PWM | Pin 2. |
| Frecuencia de la envolvente sinusoidal | 2 Hz. |
| Intervalo programado de actualización del PWM | 2 ms. |
| Entrada analógica | A0. |
| Intervalo programado de lectura | 10 ms. |
| Frecuencia nominal de adquisición | 100 muestras/s. |
| Comunicación serial | 9600 baudios. |
| Conversión a voltios | `lecturaRaw * (5.0 / 1023.0)`. |

Los 2 Hz corresponden a la envolvente sinusoidal que modifica el ciclo de trabajo, no a la frecuencia portadora del PWM. El intervalo de adquisición indicado es nominal y puede presentar variaciones debidas a la ejecución de las tareas.

## Ejecución

1. Descargar o clonar el repositorio completo, conservando sus carpetas.
2. Abrir el programa `.ino` en Arduino IDE.
3. Seleccionar Arduino Mega or Mega 2560 y el procesador ATmega2560.
4. Compilar el código. Para generar el firmware, utilizar **Programa/Sketch → Exportar binarios compilados/Export Compiled Binary**.
5. Abrir el proyecto de Proteus ubicado en `simulacion/`.
6. En la propiedad **Program File** del modelo que ejecuta el programa, seleccionar el firmware correspondiente de `simulacion/firmware/`. Actualizar la ruta si apunta al equipo de origen.
7. Verificar la salida del pin 2, la conexión del nodo sumador a A0 y el GND común.
8. Configurar el Virtual Terminal a 9600 baudios y ejecutar la simulación.
9. Revisar los voltajes del circuito y las muestras recibidas por el terminal.

El Virtual Terminal permite recibir valores numéricos. Para representar esos valores como una curva, deben procesarse con una herramienta de análisis o visualización.

## Datos

La carpeta `datos/` debe conservar los registros disponibles, con nombres que permitan identificar la prueba correspondiente:

| Registro | Información que debe identificarse |
| --- | --- |
| Ganancia diferencial | Rg en ohmios, Vin(pp) y Vout(pp) en voltios, y ganancias calculadas. |
| Modo común | Vin(pp), Vout(pp), ajuste de Rg y relación de amplitudes. |
| Acondicionamiento | Referencia del buffer y rango del nodo sumador, indicando que corresponden a simulación. |
| Adquisición digital | Muestras de voltaje y, si se conservaron, sus tiempos de adquisición. |

Conservar los nombres reales de los archivos y aclarar sus columnas, unidades y origen. Si el tiempo se reconstruye a partir del intervalo nominal de 10 ms, indicarlo; no presentarlo como una marca de tiempo medida.

## Comprobación del proyecto

Antes de publicar, abrir y ejecutar la simulación desde una copia ubicada en otra carpeta. Comprobar que se incluyeron los archivos asociados y que la ruta del firmware puede seleccionarse correctamente.

La reproducción debe utilizar los valores y ajustes del circuito publicados. El CMRR requiere una ganancia diferencial medida sin recorte y una medición de modo común con el mismo ajuste de Rg; un cociente obtenido con salida limitada no valida ese parámetro.
