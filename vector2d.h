#ifndef VECTOR2D_H
#define VECTOR2D_H

template <typename T>
class vector2d
{
	public:
        vector2d();
        vector2d(T nx, T ny);
        vector2d(const vector2d<T>& vec);
        ~vector2d();
        
        T magnitude();
        T angle();
        T dot(const vector2d<T>& vec) const;
        
        vector2d operator+(const vector2d &b) const;
        vector2d operator-(const vector2d &b) const;
        vector2d operator+=(const vector2d &b) const;
        vector2d operator-=(const vector2d &b) const;
        vector2d operator-();
        
        void operator=(const vector2d &b) const;
        
        bool operator==(const vector2d &b) const;
        
        // Variables
        T x;
        T y;
};

// Constructors and destructor

template <typename T>
vector2d<T>::vector2d()
{
	x = y = 0;
}

template <typename T>
vector2d<T>::vector2d(T nx, T ny)
{
	x = nx;
	y = ny;
}

template <typename T>
vector2d<T>::vector2d(const vector2d<T>& vec)
{
	x = vec.x;
	y = vec.y;
}

template <typename T>
vector2d<T>::~vector2d()
{

}

// Functions

template <typename T>
T vector2d<T>::magnitude()
{
	return sqrt(x * x + y * y);
}

template <typename T>
T vector2d<T>::angle()
{
	if(x == 0 && y == 0) { return 0; }
    else { return atan2(y, x); }
}
  
template <typename T>
T vector2d<T>::dot(const vector2d<T>& vec) const
{
	return x * vec.x + y * vec.y; 
}

// Operators
template <typename T>
vector2d<T> vector2d<T>::operator+(const vector2d &b) const
{
	return vector2d(x + b.x, y + b.y);
}

template <typename T>
vector2d<T> vector2d<T>::operator-(const vector2d &b) const
{
	return vector2d(x - b.x, y - b.y);
}

template <typename T>
vector2d<T> vector2d<T>::operator+=(const vector2d &b) const
{
	return vector2d(x += b.x, y += b.y);
}

template <typename T>
vector2d<T> vector2d<T>::operator-=(const vector2d &b) const
{
	return vector2d(x -= b.x, y -= b.y);
}

template <typename T>
vector2d<T> vector2d<T>::operator-() 
{
	return vector2d(-x, -y);
}

template <typename T>
void vector2d<T>::operator=(const vector2d &b) const
{
	x = b.x;
	y = b.y;
}

template <typename T>
bool vector2d<T>::operator==(const vector2d &b) const
{
	if(x == b.x & y == b.y) { return true; }
	else { return false; } 
}

#endif
