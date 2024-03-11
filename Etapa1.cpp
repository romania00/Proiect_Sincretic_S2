// C++ code
//
#define TP36_SENSOR_CHANNEL 0
#define ADC_REF_VOLTAGE 5.0

void init_ADC()
{
  ADMUX |= (1 << REFS0);
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  ADCSRA |= (1 << ADEN);
}
float read_temp()
{
  ADMUX &= 0xF0;
  ADMUX |= TP36_SENSOR_CHANNEL;
  ADCSRA |= (1 << ADSC);
  while (ADCSRA & (1 << ADSC)) {}
  uint16_t adc_value = ADC;
  float voltage = (float) adc_value * ADC_REF_VOLTAGE / 1024.0;
  float temperature = (voltage - 0.5) * 100.0;
  return temperature;
}

void setup()
{
  init_ADC();
  pinMode(0,OUTPUT);
  digitalWrite(0, LOW);
  Serial.begin(9600);
}

void loop()
{
  float temp;
  temp=read_temp();
  while (Serial.available()>0)
  {
  Serial.println("temperatura este:");
  Serial.println(temp);
  char receivedChar = Serial.read();
  if (receivedChar == 'A')
  {
    digitalWrite(0, HIGH);
  }
    else
    {
      if (receivedChar == 'S')
      {
        digitalWrite(0, LOW);
      }
    }
  }
}