#ifndef NUMBER_HPP
#define NUMBER_HPP

template <class T>
class Number
{
public:
	Number(T value)
		: m_value(value)
	{
	}

	T value() const
	{
		return m_value;
	}

	void setValue(T value)
	{
		m_value = value;
	}

	Number<T>& operator=(const T value)
	{
		m_value = value;
	}

	template <class U>
	Number<T>& operator=(const Number<U>& number)
  	{
		m_value = static_cast<T>(number.value());

		return *this;
  	}

private:
	T m_value;
};

typedef Number<int> Integer;
typedef Number<float> Float;
typedef Number<double> Double;

#endif // NUMBER_HPP
