const int pirPin = 2;     
const int ledPin = 13;  
int contadorPessoas = 0;
bool pessoaDetectada = false;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600); 
  Serial.println("Sistema de Contagem de Pessoas Iniciado");
  Serial.println("Aguardando movimento...");
}

void loop() {
  int movimento = digitalRead(pirPin);
  
  if (movimento == HIGH) {
    if (!pessoaDetectada) {
      contadorPessoas++; 
      digitalWrite(ledPin, HIGH); 
      
      Serial.print("Pessoa detectada! Total: ");
      Serial.println(contadorPessoas);
      
      pessoaDetectada = true;
      delay(2000);  
    }
  } else {

    digitalWrite(ledPin, LOW);
    pessoaDetectada = false;
  }
  
  delay(100);
}