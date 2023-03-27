char *human_readable_time (long n, char *time_string){
  int seconds = n % 60;
  int minutes = n % 3600 / 60;
  int hours = n / 3600;
  
  sprintf(time_string, "%d%d:%d%d:%d%d", 
          hours/10, hours%10, 
          minutes/10, minutes%10, 
          seconds/10, seconds%10);  
  
  return(time_string);
}
