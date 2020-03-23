# Carpeta de Campo 

## Semana 15/03 - 22/03

Escrbimos una declaracion jurada sobre la compra del NeuroSky Mindwave debido a que Matias Pierri tuvo la oportunidad de que un conocido se lo compre en USA Y abaratar costos

[Declaracion Jurada](https://github.com/matias1379/Ojo-de-van-gogh/blob/master/Presupuesto-y-documentaciones/DeclaracionSensor.pdf)

Investigamos sobre vibradores y llegamos a la conclusion de que lo mas viable es reciclar vibradores de telefonos viejos como los Nokia. Un motor vibrador es un motor comun en el cual se le pone un peso en la punta del émbolo lo que lo hace vibrar, además se coloca dentro de un contenedor que aumenta la vibración.

Establecimos el entorno de trabajo BT con arduino usando los HC-05. En base a las conclusiones confeccionamos una guía de como usar dicho entorno 

[Establecer conexion entre BT](https://github.com/matias1379/Ojo-de-van-gogh/blob/master/Presupuesto-y-documentaciones/Entorno%20de%20trabajo%20de%20Arduino%20con%20Bluetooth.md)

Usando arduino logramos hacer vibrar los vibradores extraidos del nokia usando la funcion Tone() and noTone() que te permite poner la frecuencai de vibracion la cual va a variar segun lo que se necesite

[Sistema de vibracion](https://github.com/matias1379/Ojo-de-van-gogh/blob/master/Presupuesto-y-documentaciones/Sistema%20de%20Vibraci%C3%B3n.md)

Como la raspberry se maneja con JSON estuvimos aprendiendo a como procesar un string JSON en arduino y poder hacer el intercambio de datos entre raspberry y arduino por BT. Nos dimos cuenta que para que se lean bien los datos hay que usar Serial.readString() ya que Serial.read() solo detecta que entra un char 

> **JSON** (acrónimo de  JavaScript Object Notation, «notación de objeto de JavaScript») es un  formato de texto sencillo para el intercambio de datos.

Empezamos a trabajar con el sensor cerebral conectado a un telefono y logramos que cuando parpadee el usuario el telefono lo detecte pero esto es una app y no nos permite tocarla mucho para usarla en nuestro arduino pero era a modo de primeros pasos. Usando un modulo bluetooth y comandandolo por AT tratamos de configurarlo insertando los siguientes datos

> Baudrate = "576000"
>
> BIND ADDR= "0081,f9,29eb31"
>
> PSSW = "1234"

Con esta configuracion no funciono ya que la password estaba mal puesta. VIendo la documentacion nos dimos cuenta que la pass es 0000

> PSSW CORRECTA ="0000"

Ya de esta forma pudimos conectar el arduino con el HC-05 pero con el example que nos da el fabricante solo podemos medir nivel de atencion y relajacion. Tenemos que investigar como medir nivel de pestañeo. Sin embargo hicimos una prueba donde se prenden leds de acuerdo a que tan concentrado esta el usuario

Establecimos el entorno de trabajo en Google VIsion IA que es usar la Nube de google para, a traves de un sistema de redes neuronales, obtener un analizis de lo que se ve en una foto. Para esto tuvimos que crear un projecto en Google Cloud Services y habilitar la api de Google Vision AI. Una vez habilitado esto nos dan un archivo JSON que tiene nuestra API Key y la insertamos en la raspberry usando 

```Raspbian Terminal
export GOOGLE_APPLICATION_CREDENTIALS=/home/pi/filename.json
```

Una vez seteada la raspberry se usan los siguientes comandos para instalar las dependencias necesarias

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

Y este ejemplo para poder probar el analizis de la foto 

```Raspbian terminal
python3 camera_vision_face.py
```

Nos devuelve este analizis donde la raspberry se encargo de detectar las personas que aparecen en la foto en este caso Theo. Lo borroso de la foto se debe a que theo tiene el celu que no enfoca, la definicion en si de la Pi Camera es bastante buena

<img src="/home/matias/Downloads/WhatsApp Image 2020-03-18 at 22.57.52.jpeg" alt="Un tipo que maneja inteligencia artificial" style="zoom: 33%;" />

Ahora tenemos que ver como usar la raspberry para conectarla al BT y ademas que todos estos programas que describimos antes esten funcionando en Loop y de forma automatica cuando se prende la raspberry.

## Semana 22/03 - 29/03

Estuvimos viendo documentaciones y aparentemetne para poder leer el valor de BLink Strength tenemos que escribir en el registro **0x16** 

![Registros tabla](/home/matias/Downloads/RegistrosNeurosky.jpeg)

