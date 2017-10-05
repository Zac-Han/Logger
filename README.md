# Logger
## SingleTon
~~~c++
//header file
class Singleton  
{
    public:
        static Singleton& Instance()
        {
            if (instance_ == NULL)
            {
                instance_ = new Singleton;
            }
            return *instance_;
         }
    private:
        Singleton()；
        ~Singleton()；
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
    private:
        static Singleton* instance_;
};
//cpp file
Singleton* Singleton::instance_ = 0;  
~~~
