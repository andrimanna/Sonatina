# Sonatina
**S**u**ON**eri**A** remo**T**a per c**I**tofono vi**N**t **A**ge

Due ESP32 nella stessa rete Wi-Fi fungono da server e client. L'ESP server è collegato ad uno speaker attraverso un 2N2222A (come amplificatore) al pin D2 ed è in ascolto sulla porta 80. Quando viene effettuata una richiesta HTTP, verrà riprodotto un gingle. L'ESP client è collegato al pin D2 in modalità `INPUT_PULLUP` ad un fotoaccoppiatore EL817 per separare l'ESP dalla 12V AC proveniente dal citofono. L'altro lato del fotoaccoppiatore è in parallelo alla bobina del ronzartore dell'apparecchio originale con una resitenza da 1KΩ in serie.

Prima di caricare i due sketch Arduno negli ESP32, assegare un ip statico nel router per l'ESP server, copiarlo nella stringa `#define ip "http://192.168.X.X"` nel file client.ino e inserire l'SSID e la password della propria rete Wi-Fi in entrambi i file nelle relative stringhe `const char* ssid = "SSID";` e `const char* password = "PASSWORD";` 

Il client è necessario installarlo in prossimità del citofono, mentre il server è possibile posizionarlo ovunque ci sia segnale Wi-Fi.
Per l'alimentazione è possibile utilizzare due vecchi caricabatterie da 5V DC.

ESP server nella sua scatola aperta:

![ESP server nella sua scatola aperta](https://github.com/andrimanna/Sonatina/raw/master/foto/server_aperto.png "server aperto")

ESP server nella sua scatola chiusa:

![ESP server nella sua scatola chiusa](https://github.com/andrimanna/Sonatina/raw/master/foto/server_chiuso.png "server chiuso")

ESP client nella sua scatola aperta:

![ESP client nella sua scatola aperta](https://github.com/andrimanna/Sonatina/raw/master/foto/client.png "client")
