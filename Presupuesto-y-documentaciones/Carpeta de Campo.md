# Carpeta de Campo 

## Semana 15/03 - 22/03

Escribimos una declaración jurada sobre la compra del NeuroSky Mindwave debido a que Matías Pierri tuvo la oportunidad de que un conocido se lo compre en USA Y abaratar costos

[Declaracion Jurada](https://github.com/matias1379/Ojo-de-van-gogh/blob/master/Presupuesto-y-documentaciones/DeclaracionSensor.pdf)

Investigamos sobre vibradores y llegamos a la conclusión de que lo mas viable es reciclar vibradores de teléfonos viejos como los Nokia. Un motor vibrador es un motor común en el cual se le pone un peso en la punta del émbolo lo que lo hace vibrar, además se coloca dentro de un contenedor que aumenta la vibración.

Establecimos el entorno de trabajo BT con Arduino usando los HC-05. En base a las conclusiones confeccionamos una guía de como usar dicho entorno 

[Establecer conexion entre BT](https://github.com/matias1379/Ojo-de-van-gogh/blob/master/Presupuesto-y-documentaciones/Entorno%20de%20trabajo%20de%20Arduino%20con%20Bluetooth.md)

Usando Arduino logramos hacer vibrar los vibradores extraídos del Nokia usando la función Tone() and noTone() que te permite poner la frecuencia de vibración la cual va a variar según lo que se necesite

[Sistema de vibracion](https://github.com/matias1379/Ojo-de-van-gogh/blob/master/Presupuesto-y-documentaciones/Sistema%20de%20Vibraci%C3%B3n.md)

Como la Raspberry se maneja con JSON estuvimos aprendiendo a como procesar un string JSON en Arduino y poder hacer el intercambio de datos entre Raspberry y Arduino por BT. Nos dimos cuenta que para que se lean bien los datos hay que usar Serial.readString() ya que Serial.read() solo detecta que entra un char 

> **JSON** (acrónimo de  JavaScript Object Notation, «notación de objeto de JavaScript») es un  formato de texto sencillo para el intercambio de datos.

Empezamos a trabajar con el sensor cerebral conectado a un teléfono y logramos que cuando parpadee el usuario, el teléfono lo detecte pero esto es una app y no nos permite tocarla mucho para usarla en nuestro Arduino pero era a modo de primeros pasos. Usando un modulo bluetooth y comandándolo por AT tratamos de configurarlo insertando los siguientes datos

> Baudrate = "576000"
>
> BIND ADDR= "0081,f9,29eb31"
>
> PSSW = "1234"

Con esta configuración no funciono ya que la password estaba mal puesta. Viendo la documentación nos dimos cuenta que la pass es 0000

> PSSW CORRECTA ="0000"

Ya de esta forma pudimos conectar el Arduino con el HC-05 pero con el example que nos da el fabricante solo podemos medir nivel de atención y relajación. Tenemos que investigar como medir nivel de pestañeo. Sin embargo hicimos una prueba donde se prenden leds de acuerdo a que tan concentrado esta el usuario

Establecimos el entorno de trabajo en Google Visión IA que es usar la Nube de Google para, a través de un sistema de redes neuronales, obtener un análisis de lo que se ve en una foto. Para esto tuvimos que crear un proyecto en Google Cloud Services y habilitar la api de Google Vision AI. Una vez habilitado esto nos dan un archivo JSON que tiene nuestra API Key y la insertamos en la Raspberry usando 

```Raspbian Terminal
export GOOGLE_APPLICATION_CREDENTIALS=/home/pi/filename.json
```

Una vez seteada la Raspberry se usan los siguientes comandos para instalar las dependencias necesarias

```Linux Terminal
   python3 -m pip install --user pip
   python3 -m pip install --user google-cloud-vision
   python3 -m pip install --user Pillow
   python3 -m pip install --user picamera
```

Usamos este comando para sacar una foto 

```RAspbian
   raspistill -o cam.jpg
```

Y este ejemplo para poder probar el análisis de la foto 

```Raspbian terminal
python3 camera_vision_face.py
```

Nos devuelve este análisis donde la Raspberry se encargo de detectar las personas que aparecen en la foto en este caso Theo. Lo borroso de la foto se debe a que Theo tiene el celu que no enfoca, la definición en si de la Pi Camera es bastante buena

<img src="/home/matias/Downloads/WhatsApp Image 2020-03-18 at 22.57.52.jpeg" alt="Un tipo que maneja inteligencia artificial" style="zoom: 33%;" />

Ahora tenemos que ver como usar la Raspberry para conectarla al BT y además que todos estos programas que describimos antes estén funcionando en Loop y de forma automática cuando se prende la Raspberry.

## Semana 22/03 - 29/03

Estuvimos viendo documentaciones y aparentemente para poder leer el valor de Blink Strength tenemos que escribir en el registro **0x16** 

![Registros tabla](/home/matias/Downloads/RegistrosNeurosky.jpeg)

Se hicieron ejemplos con Arduino para empezar a leer los datos Json que se recibirán de la Raspberry. Se han hecho pruebas de como formar un Json y como obtener el valor de Json.
Luego se probo mandar archivos String por BT, pero nos dimos cuenta que la función no permite mandar Strings por BT:

```
BTMaster.write()
```
Se ha visto varios videos o formas de intentar mandar el String por BT de otra forma, pero no se ha conseguido, entonces se empezó a investigar para pasar un String a un char Array. Se ha encontrado un ejemplo en el que muestra que la función: 
```
str.toCharArray(charArray,buf)
```
Siendo str el String ingresado, charArray, la variable donde se guarda el charArray y buf la cantidad máxima a convertir de String en char Array.

Se ha tenido problemas con esta función ya que dependiendo del orden en el que se declaraba el String, funcionaba o no. Pero se ha logrado descubrir el error, creando 2 programas: 
-	Uno que simula el parpadeo, sacar foto y mandar el String Json por BT a través de un charArray
-	El otro que recibe el char Array y lo convierte en un String, y obtiene el valor del Json de color y de acuerdo al color realiza una vibración
[Sistema de vibraciones con Json y BT](https://github.com/matias1379/Ojo-de-van-gogh/blob/master/Presupuesto-y-documentaciones/Sistema%20de%20vibraciones%20de%20acuerdo%20al%20color.md)