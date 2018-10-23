class Display {
  private :
      void setup(int pin,int pin_mode){
          pinMode(pin, pin_mode);
      }
  public :
      int * _pins;
      int _count ;
      void start(int pins,int count = 0){
          _pins = pins;
          _count = count;
          for(int i=0;i<_count;i++)
              setup(_pins[i],OUTPUT);
      }
      void on(int pin){
          digitalWrite(pin, HIGH);
      }
      void off(int pin){
          digitalWrite(pin, LOW);
      }
      void rDisplay(int width = 1,int sleep = 500){
          for (int i=0;i<_count;i++){
              on(_pins[i]);
              delay(sleep);
              off(_pins[_count-width+i < _count  ? _count-width+i : i-width]);
          }
      }
};

const int SLEEP = 500 ; //milisecond
const int WIDTH = 3; // ON LEDs Before of current LED

const int TOTAL = 2; // Number of LEDs
const int PINS[TOTAL] = {8,9,10,11}; // List of Ports for Using LEDs

Display disp;
void setup() {
    disp.start(PINS,TOTAL);
}
void loop() {
    disp.rDisplay(WIDTH,SLEEP);
}