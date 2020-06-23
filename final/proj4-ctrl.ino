#define _SH_STEPPER_DIR_PIN  4
#define _SH_STEPPER_STEP_PIN 5
#define _SH_STEPPER_EN_PIN   6
#define _SH_ANALOG_IN_PIN    A0
#define _SH_MAX_ANALOG       660
#define _SH_MIN_ANALOG       0
#define _SH_DELTA_PER_CIRCLE 25

int initial_sensor_value,sensor_value,output_RF,delay_value;

void setup(){
  // Set up Stepper Motor.
  pinMode(_SH_STEPPER_DIR_PIN,OUTPUT); 
  pinMode(_SH_STEPPER_STEP_PIN,OUTPUT); 
  pinMode(_SH_STEPPER_EN_PIN,OUTPUT);
  digitalWrite(_SH_STEPPER_EN_PIN,LOW);
  digitalWrite(_SH_STEPPER_DIR_PIN,LOW);

  // Initialize Serial
  Serial.begin(9600);

  // Initialize Sensor
  initial_sensor_value=analogRead(_SH_ANALOG_IN_PIN);
  Serial.print("[guestsh1/INFO] Read sensor value ");
  Serial.println(initial_sensor_value);
  if(initial_sensor_value>=_SH_MAX_ANALOG-_SH_DELTA_PER_CIRCLE){
    initial_sensor_value=_SH_MAX_ANALOG-_SH_DELTA_PER_CIRCLE;
  }
  if(initial_sensor_value<=_SH_MIN_ANALOG+_SH_DELTA_PER_CIRCLE){
    initial_sensor_value=_SH_MIN_ANALOG+_SH_DELTA_PER_CIRCLE;
  }
  Serial.print("[guestsh1/INFO] Initialized sensor value as ");
  Serial.println(initial_sensor_value);
}  


void loop(){
  // Initial RF is 2048 RF/t
  // Refer to teamcofh.com for more info about RF.
  // ps: RF is a widely used energy unit in Minecraft, first introduced by teamcofh.
  sensor_value=analogRead(_SH_ANALOG_IN_PIN);
  //Serial.print(sensor_value);
  //Serial.print(" ");
  if(sensor_value<=initial_sensor_value-_SH_DELTA_PER_CIRCLE){
    sensor_value=-1;
  }
  if(sensor_value>=initial_sensor_value+_SH_DELTA_PER_CIRCLE){
    sensor_value=-1;
  }
  //Serial.print(sensor_value-initial_sensor_value);
  //Serial.print(" ");
  //delay_value=map(sensor_value-initial_sensor_value,-25,25,0,3600);
  //Serial.println(delay_value);
  /*if(delay_value<=1200){
    digitalWrite(_SH_STEPPER_STEP_PIN,HIGH);
    delayMicroseconds(800);
    digitalWrite(_SH_STEPPER_STEP_PIN,LOW);
    delayMicroseconds(800);
  }
  else if(delay_value<=1800){
    digitalWrite(_SH_STEPPER_STEP_PIN,HIGH);
    delayMicroseconds(1200);
    digitalWrite(_SH_STEPPER_STEP_PIN,LOW);
    delayMicroseconds(1200);
  }
  else if(delay_value<=2400){
    digitalWrite(_SH_STEPPER_STEP_PIN,HIGH);
    delayMicroseconds(1800);
    digitalWrite(_SH_STEPPER_STEP_PIN,LOW);
    delayMicroseconds(1800);
  }
  else if(delay_value<=3000){
    digitalWrite(_SH_STEPPER_STEP_PIN,HIGH);
    delayMicroseconds(2400);
    digitalWrite(_SH_STEPPER_STEP_PIN,LOW);
    delayMicroseconds(2400);
  }
  else{
    digitalWrite(_SH_STEPPER_STEP_PIN,HIGH);
    delayMicroseconds(3000);
    digitalWrite(_SH_STEPPER_STEP_PIN,LOW);
    delayMicroseconds(3000);
  }*/
  if(sensor_value==-1){
    digitalWrite(_SH_STEPPER_DIR_PIN,HIGH);
    digitalWrite(_SH_STEPPER_STEP_PIN,HIGH);
    delayMicroseconds(800);
    digitalWrite(_SH_STEPPER_STEP_PIN,LOW);
    delayMicroseconds(800);
  }
  else{
    digitalWrite(_SH_STEPPER_DIR_PIN,LOW);
    digitalWrite(_SH_STEPPER_STEP_PIN,HIGH);
    delayMicroseconds(800);
    digitalWrite(_SH_STEPPER_STEP_PIN,LOW);
    delayMicroseconds(800);
  }
}
