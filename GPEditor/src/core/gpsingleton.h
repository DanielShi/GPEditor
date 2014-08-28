#ifndef GPSINGLETON_H
#define GPSINGLETON_H
#include <stddef.h>

template <class T>
class GPSingleton
{
public:
    inline static T* getInstance()
    {
        if( m_instance == NULL )
        {
            m_instance = new T();
        }
        return m_instance;
    }

protected:
    explicit GPSingleton(){}

    explicit GPSingleton(const GPSingleton& instance){}

    virtual ~GPSingleton(){}
private:
    static T*  m_instance;


};

template<class T>
T* GPSingleton<T>::m_instance = NULL;

#endif // GPSINGLETON_H
