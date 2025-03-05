int studentCounter=0;

mutex counter_mutex=1;

mutex classReady_mutex=1;

cond_var classReady;

mutex joined_mutex=1;

cond_var joined;




joinClass{

      mutex_lock(classReady_mutex);

      while(studentCounter==10)      //wait for the previous class to start if there are already 10 students

             cond_wait(classReady,classReady_mutex);

       mutex_unlock(classReady_mutex);


      mutex_lock(counter_mutex);

      studentCounter++;

      mutex_unlock(counter_mutex);

      

      cond_signal(joined);

      

      mutex_lock(classReady_mutex);

      cond_wait(classReady,classReady_mutex);

      mutex_unlock(classReady_mutex);

      startClass();

}

createClass{

     mutex_lock(joined_mutex);

     while(studentCounter<10)     
          cond_wait(joined,joined_mutex);

    mutex_unlock(joined_mutex);

    cond_signal(classReady);

    startClass();

    mutex_lock(counter_mutex);

    studentCounter=0;

    mutex_lock(counter_mutex);
}

