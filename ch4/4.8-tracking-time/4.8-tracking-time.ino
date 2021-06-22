// generally bad Idea to use delay()
// returns the number milliseconds that have elapsed since the star of the
// programat the star of each loop. 
int trackTimeMilliseconds(int &last_time, unsigned int &MS_per_beat, boolean &on, int speakerPin, int frequency, int duration) {
    long current_time = millis();
    if((current_time - last_time >= MS_per_beat) && on == true) {
        tone(speakerPin, frequency, duration);
        last_time = current_time;
    }
    return last_time;
}