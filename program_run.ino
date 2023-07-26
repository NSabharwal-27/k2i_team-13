// C++ code
// #include <Adafruit_LiquidCrystal.h>
// Adafruit_LiquidCrystal lcd_1(0);
  #include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd_1 (0x27, 20, 4);
  float voltage_conversion = 0;
  float resistance_conversion = 0;
  float input_voltage = 0;
  float temp=0.0;
 const int buzzer= 7;
  int seconds = 0;

void setup()
{
  lcd_1.init();
  lcd_1.backlight(); //turn on the backlight
  pinMode(7, OUTPUT);
  lcd_1.begin(16, 2);
}

void loop()
{
  delay(1000);
  //Conversion formula
  float analog_value = analogRead(A0);
  voltage_conversion = (analog_value * 5.0) / 1024.0;
//resistance_conversion = (analog_value * 250.0) / 1024.0;
  input_voltage = voltage_conversion;
//input_resistance= resistance_conversion;
// current= input_voltage/input_resistance
if((input_voltage)>2.5) {
  analogWrite(9, 127);
  tone(buzzer, 1000);
}
else {
  noTone(buzzer);
  analogWrite(9,0);
}
  
  lcd_1.setCursor(1, 0);
  lcd_1.print("Voltage= ");
  lcd_1.print(input_voltage);

  lcd_1.setCursor(0, 1);
 
  lcd_1.print(seconds);
  lcd_1.setBacklight(1);
  delay(500); // Wait for 500 millisecond(s)
 // lcd_1.setBacklight(0);
  delay(500); // Wait for 500 millisecond(s)
  seconds += 1;


}
