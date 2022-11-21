#pragma once
#include<iostream>

namespace MATH
{
	struct mat3
	{
		float num[3][3];
	public:
		mat3() { ; };

		mat3(float a, float b, float c,
			float d, float e, float f,
			float g, float h, float i)
		{
			num[0][0] = a; num[0][1] = b; num[0][2] = c;
			num[1][0] = d; num[1][1] = e; num[1][2] = f;
			num[2][0] = g; num[2][1] = h; num[2][2] = i;
		}

		mat3& operator*(const mat3& m) const;
		mat3 operator+(const mat3& m) const;
		mat3 operator-(const mat3& m) const;
		mat3 operator*(const int& m)const;
		mat3 operator/(const int& m)const;
		
		// mat3 * mat3 ������
		mat3& operator*(const mat3& m)
		{
			mat3 mm = m;
			mat3 rm = (*this);

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					mm.num[j][i] = 0;
					for (int k = 0; k < 3; k++)
					{
						mm.num[j][i] += rm.num[j][k] * m.num[k][i];
					}
				}
			}
			//���ϰ�
			return mm;
		}

		//mat3 + mat3 ������
		mat3& operator+(const mat3 m)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					this->num[i][j] = this->num[i][j] + m.num[i][j];
				}
			}
			return (*this);
		}
		//mat3 - mat3 ������
		mat3& operator-(const mat3 m)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					this->num[i][j] = this->num[i][j] - m.num[i][j];
				}
			}
			return (*this);
		}
		//mat3�� ����� ������
		mat3& operator*(const int m)
		{
			mat3 sm = (*this);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					sm.num[i][j] = this->num[i][j] * m;
				}
			}
			return sm;
		}
		//mat3 ��� ������ ������
		mat3& operator/(const int m)
		{
			mat3 sm = (*this);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					sm.num[i][j] = this->num[i][j] / m;
				}
			}
			return sm;
		}

		//mat3�� ��¿�����
		friend std::ostream& operator << (std::ostream& out, mat3& v)
		{
			//��� ����
			out << "(" << v.num[0][0] << "," << v.num[0][1] << "," << v.num[0][2] << ")\n"
				<< "(" << v.num[1][0] << "," << v.num[1][1] << "," << v.num[1][2] << ")\n"
				<< "(" << v.num[2][0] << "," << v.num[2][1] << "," << v.num[2][2] << ")\n";
			//���ϰ�
			return out;
		}

	};

	struct mat4
	{
		//����� ���� �׸� num
		float num[4][4];

	public:
		//����ü �����Ҷ� �ʱⰪ ���� ������ �ִ� ����
		mat4() { ; };
		//����ü�� �ʱⰪ �����Ҷ� ���� �Ű������� ��� num�� �־���
		mat4(float a, float b, float c, float d,
			float e, float f, float g, float h,
			float i, float j, float k, float l,
			float m, float n, float o, float p) {
			num[0][0] = a; num[0][1] = b; num[0][2] = c; num[0][3] = d;
			num[1][0] = e; num[1][1] = f; num[1][2] = g; num[1][3] = h;
			num[2][0] = i; num[2][1] = j; num[2][2] = k; num[2][3] = l;
			num[3][0] = m; num[3][1] = n; num[3][2] = o; num[3][3] = p;
		};

		mat4 operator*(const mat4 m) const;
		mat4 operator+(const mat4 m) const;
		mat4 operator-(const mat4 m) const;
		mat4 operator*(const int& m)const;
		mat4 operator/(const int& m)const;

		//mat4 * mat4 ������
		mat4& operator*(const mat4 m)
		{
			mat4 mm = m;
			mat4 rm = (*this);

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					mm.num[j][i] = 0;
					for (int k = 0; k < 4; k++)
					{
						mm.num[j][i] += m.num[j][k] * rm.num[k][i];
					}
				}
			}
			//���ϰ�
			return mm;
		}
		//mat4 + mat4 ������
		mat4& operator+(const mat4 m)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					this->num[i][j] = this->num[i][j] + m.num[i][j];
				}
			}
			return (*this);
		}
		//mat4 - mat4 ������
		mat4& operator-(const mat4 m)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					this->num[i][j] = this->num[i][j] - m.num[i][j];
				}
			}
			return (*this);
		}
		//mat4�� ����� ������
		mat4& operator*(const int m)
		{
			mat4 sm = (*this);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					sm.num[i][j] = this->num[i][j] * m;
				}
			}
			return sm;
		}
		//mat4�� ��� ������ ������
		mat4& operator/(const int m)
		{
			mat4 sm = (*this);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					sm.num[i][j] = this->num[i][j] / m;
				}
			}
			return sm;
		}
		//mat4 ��� ������
		friend std::ostream& operator << (std::ostream& out, mat4& v)
		{
			//��� ����
			out << "(" << v.num[0][0] << "," << v.num[0][1] << "," << v.num[0][2] << "," << v.num[0][3] << ")\n"
				<< "(" << v.num[1][0] << "," << v.num[1][1] << "," << v.num[1][2] << "," << v.num[1][3] << ")\n"
				<< "(" << v.num[2][0] << "," << v.num[2][1] << "," << v.num[2][2] << "," << v.num[2][3] << ")\n"
				<< "(" << v.num[3][0] << "," << v.num[3][1] << "," << v.num[3][2] << "," << v.num[3][3] << ")\n";
			//���ϰ�
			return out;
		}
	};
	struct vec3
	{
		//����Ҷ� ����� �׸�vm�� ������� ���� ����� �׸� vec
		float num[3][1];
		float vm[3][1];
		float num2[1][3];

	public:
		//����ü �����Ҷ� �ʱⰪ���� ����
		vec3() { ; };
		//����ü �����Ҷ� �ʱⰪ�� �Ű������� ��� vec�� �־���
		vec3(float a, float b) {
			num[0][0] = a; num[1][0] = b; num[2][0] = 1;
			num2[0][0] = a; num2[0][1] = b; num[2][0] = 1;

		}
		vec3(float a, float b, float c) {
			num[0][0] = a; num[1][0] = b; num[2][0] = c;
			num2[0][0] = a; num2[0][1] = b; num2[0][2] = c;

		}
		//�ش� ����ü�� mat����ü�� * ������ ���� �����ε� operator*(const mat3) 
		vec3& operator*(const mat3 m) const;
		vec3& operator*(const vec3& m) const;
		vec3& operator+(const vec3 m) const;
		vec3& operator-(const vec3 m) const;
		vec3& operator*(const int m) const;
		vec3& operator/(const int m) const;

		/*mat3 operator*(const vec3 m) const;*/

		//��� *�������ϰ� vm�� ���� �־��ֱ� vec�� ������ ����� ���� �� ������� �ٸ��� �����
		vec3 operator*(const mat3& m)
		{
			vec3 savemat = vec3(0, 0, 0);
			vec3 savevec = (*this);

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
				{
					savemat.num[i][0] += m.num[i][j] * savevec.num[j][0];
				}
				//this->num[i][0] = savemat.num[i][0];

			}

			//���ϰ�
			return savemat;
		}
		//vec3 * vec3 ��Į�� �� ������ ������
		vec3 operator*(const vec3 m)
		{
			this->vm[0][0] = num[1][0] * m.num[2][0] - m.num[2][0] * m.num[1][0];
			this->vm[1][0] = num[2][0] * m.num[0][0] - m.num[0][0] * m.num[2][0];
			this->vm[2][0] = num[0][0] * num[1][0] - m.num[1][0] * m.num[0][0];

			this->num[0][0] = vm[0][0];
			this->num[1][0] = vm[1][0];
			this->num[2][0] = vm[2][0];
			this->num2[0][0] = vm[0][0];
			this->num2[0][1] = vm[1][0];
			this->num2[0][2] = vm[2][0];

			return (*this);
		}
		//vec3 + vec3 ������
		vec3 operator+(const vec3 m)
		{
			for (int i = 0; i < 3; i++)
			{
				this->num[i][0] = this->num[i][0] + m.num[i][0];
				this->num2[0][i] = this->num2[0][i] + m.num2[0][i];
			}
			return (*this);
		}
		//vec3 - vec3 ������
		vec3 operator-(const vec3 m)
		{
			for (int i = 0; i < 3; i++)
			{
				this->num[i][0] = this->num[i][0] - m.num[i][0];
				this->num2[0][i] = this->num2[0][i] - m.num2[0][i];
			}
			return (*this);
		}
		// vec3�� ����� ������
		vec3 operator*(const int m)
		{
			vec3 mm = (*this);
			for (int i = 0; i < 3; i++)
			{
				mm.num[i][0] = this->num[i][0] * m;
				mm.num2[0][i] = this->num[0][i] * m;
			}
			return mm;
		}
		//vec3�� ��� ������ ������
		vec3 operator/(const int m)
		{
			vec3 mm = (*this);
			for (int i = 0; i < 3; i++)
			{
				mm.num[i][0] = this->num[i][0] / m;
				mm.num2[0][i] = this->num[0][i] / m;
			}
			return mm;
		}


		//��� ������
		friend std::ostream& operator << (std::ostream& out, vec3& v)
		{
			//��� ����
			out << "(" << v.num2[0][0] << "," << v.num2[0][1] << "," << v.num2[0][2] << ")\n";
			//���ϰ�
			return out;
		}
	};
	struct vec4
	{
		//����Ҷ� ����� �׸�vm�� ������� ���� ����� �׸� vec
		float num[4][1];
		float vm[4][1];
		float num2[1][4];
	public:
		//����ü �����Ҷ� �ʱⰪ���� ����
		vec4() { ; };
		//����ü �����Ҷ� �ʱⰪ�� �Ű������� ��� vec�� �־���
		vec4(float x, float y, float z) {
			num[0][0] = x; num[1][0] = y; num[2][0] = z; num[3][0] = 1;
			num2[0][0] = x; num2[0][1] = y; num2[0][2] = z; num2[0][3] = 1;
		}
		vec4(float x, float y, float z, float h) {
			num[0][0] = x; num[1][0] = y; num[2][0] = z; num[3][0] = h;
			num2[0][0] = x; num2[0][1] = y; num2[0][2] = z; num2[0][3] = h;
		}
		//�ش� ����ü�� mat����ü�� * ������ ���� �����ε� operator*(const mat3) 
		vec4 operator*(const mat4 m) const;
		//vec4 operator*(const vec4 m) const;
		vec4 operator+(const vec4 m) const;
		vec4 operator-(const vec4 m) const;
		vec4 operator*(const int m) const;
		vec4 operator/(const int m) const;

		//��� *�������ϰ� vm�� ���� �־��ֱ� vec�� ������ ����� ���� �� ������� �ٸ��� �����
		vec4 operator*(const mat4& m)
		{
			this->vm[0][0] = num[0][0] * m.num[0][0] + num[1][0] * m.num[1][0] + num[2][0] * m.num[2][0] + num[3][0] * m.num[3][0];
			this->vm[1][0] = num[0][0] * m.num[0][1] + num[1][0] * m.num[1][1] + num[2][0] * m.num[2][1] + num[3][0] * m.num[3][1];
			this->vm[2][0] = num[0][0] * m.num[0][2] + num[1][0] * m.num[1][2] + num[2][0] * m.num[2][2] + num[3][0] * m.num[3][2];
			this->vm[3][0] = num[0][0] * m.num[0][3] + num[1][0] * m.num[1][3] + num[2][0] * m.num[2][3] + num[3][0] * m.num[3][3];

			//������ ������ ���� ��� ���� �ٽ� vec�� �־������ν� ���� *������ �Ҷ� ������� �ٸ��� ��µ�
			this->num[0][0] = vm[0][0];
			this->num[1][0] = vm[1][0];
			this->num[2][0] = vm[2][0];
			this->num[3][0] = vm[3][0];
			this->num2[0][0] = vm[0][0];
			this->num2[0][1] = vm[1][0];
			this->num2[0][2] = vm[2][0];
			this->num2[0][3] = vm[3][0];

			//���ϰ�
			return (*this);
		}
		//vec4 operator*(const vec4 m)
		//{
		//	this->vm[0][0] = num[1][0] * m.num[2][0] - m.num[2][0] * m.num[1][0];
		//	this->vm[1][0] = num[2][0] * m.num[0][0] - m.num[0][0] * m.num[2][0];
		//	this->vm[2][0] = num[0][0] * num[1][0] - m.num[1][0] * m.num[0][0];
		//	this->num[0][0] = vm[0][0];
		//	this->num[1][0] = vm[1][0];
		//	this->num[2][0] = vm[2][0];
		//	this->num2[0][0] = vm[0][0];
		//	this->num2[0][1] = vm[1][0];
		//	this->num2[0][2] = vm[2][0];
		//	return (*this);
		//}

		//vec4 + vec4 ������
		vec4 operator+(const vec4 m)
		{
			for (int i = 0; i < 4; i++)
			{
				this->num[i][0] = this->num[i][0] + m.num[i][0];
				this->num2[0][i] = this->num2[0][i] + m.num2[0][i];
			}
			return (*this);
		}
		//vec4 - vec4 ������
		vec4 operator-(const vec4 m)
		{
			for (int i = 0; i < 4; i++)
			{
				this->num[i][0] = this->num[i][0] - m.num[i][0];
				this->num2[0][i] = this->num2[0][i] - m.num2[0][i];
			}
			return (*this);
		}
		//vec4�� ����� ������
		vec4 operator*(const int m)
		{
			vec4 mm = (*this);
			for (int i = 0; i < 4; i++)
			{
				mm.num[i][0] = this->num[i][0] * m;
				mm.num2[0][i] = this->num[0][i] * m;
			}
			return mm;
		}
		//vec4 ������ ������
		vec4 operator/(const int m)
		{
			vec4 mm = (*this);
			for (int i = 0; i < 4; i++)
			{
				mm.num[i][0] = this->num[i][0] / m;
				mm.num2[0][i] = this->num[0][i] / m;
			}
			return mm;
		}
		//��� ������
		friend std::ostream& operator << (std::ostream& out, vec4& v)
		{
			//��� ����
			out << "(" << v.num[0][0] << "," << v.num[1][0] << "," << v.num[2][0] << "," << v.num[3][0] << ")\n";
			//���ϰ�
			return out;
		}
	};

	//vec3���·� ���ϵǴ� mat3 * vec3 ������
	//vec3 operator*(mat3& m, const vec3& v3m);
	vec3 operator*(mat3& m, const vec3& v3m)
	{
		vec3 savemat = vec3(0, 0, 0);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				savemat.num[i][0] += v3m.num[j][0] * m.num[i][j];
				//savemat.num2[0][i] = savemat.num[i][0];
			}
		}
		return savemat;
	}
	//vec4���·� ���ϵǴ� mat4 * vec4 ������
	/*vec4 operator*(mat4& m, const vec4& v3m);*/
	vec4 operator*(mat4& m, const vec4& v3m)
	{
		vec4 savemat = vec4(0, 0, 0, 0);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
			{
				savemat.num[i][0] += m.num[i][j] * v3m.num[j][0];
				savemat.num2[0][i] = savemat.num[i][0];
			}
		}
		return savemat;
	}

	float radians(float m)
	{
		float mm;
		mm = m * 3.14 / 180;
		return mm;
	}

	//����� ��ġ���ִ� �Լ�
	void transposeMatrix(mat3& m) {
		mat3 tm = m;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m.num[i][j] = tm.num[j][i];
			}
		}
	}
	void transposeMatrix(mat4& m) {
		mat4 tm = m;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				m.num[i][j] = tm.num[j][i];
			}
		}
	}

	//���͸� ��ġ���ִ� �Լ�
	void transposeVector(vec3& m) {
		vec3 tm = m;

		for (int j = 0; j < 3; j++)
		{
			m.num[j][0] = tm.num2[0][j];
			m.num2[0][j] = tm.num[j][0];
		}

	}
	void transposeVector(vec4& m) {
		vec4 tm = m;

		for (int j = 0; j < 4; j++)
		{
			m.num[j][0] = tm.num2[0][j];
			m.num2[0][j] = tm.num[j][0];
		}
	}

	//������ķ� �ʱ�ȭ�ϴ� �Լ�
	void identityMatrix(mat3& m) {

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				if (i == j)
				{
					m.num[i][j] = 1;
				}
				else
				{
					m.num[i][j] = 0;
				}
			}
		}
	}
	void identityMatrix(mat4& m) {

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{

				if (i == j)
				{
					m.num[i][j] = 1;
				}
				else
				{
					m.num[i][j] = 0;
				}
			}
		}
	}

	//�������ͷ� �ʱ�ȭ�ϴ� �Լ�
	void identityVector(vec3& m) {

		for (int i = 0; i < 3; i++)
		{
			m.num[i][0] = 1;
			m.num2[0][i] = 1;
		}
	}
	void identityVector(vec4& m) {

		for (int i = 0; i < 4; i++)
		{
			m.num[i][0] = 1;
			m.num2[0][i] = 1;
		}
	}

	//��ĳ����� ��, ��İ� ���Ͱ� �Լ�
	mat3 multiplyMatrix(mat3 m1, mat3 m2) {
		mat3 mm;
		mm = m1 * m2;
		return mm;
	}
	mat4 multiplyMatrix(mat4 m1, mat4 m2) {
		mat4 mm;
		mm = m1 * m2;
		return mm;
	}
	vec3 multiplyMatrix(mat3 m1, vec3 m2) {
		vec3 mm;
		mm = m1 * m2;
		return mm;
	}
	vec4 multiplyMatrix(mat4 m1, vec4 m2) {
		vec4 mm;
		mm = m1 * m2;
		return mm;
	}

	//���ͳ����� ��, ���Ϳ� ��İ� �Լ�
	vec3 multiplyVector(vec3 m1, mat3 m2) {
		vec3 mm;
		mm = m1 * m2;
		return mm;
	}
	vec4 multiplyVector(vec4 m1, mat4 m2) {
		vec4 mm;
		mm = m1 * m2;
		return mm;
	}
	vec3 multiplyVector(vec3 m1, vec3 m2) {
		vec3 mm;

		mm = m1 * m2;
		return mm;
	}
	//vec4 multiplyVector(vec4 m1, vec4 m2) {
	//		vec4 mm;
	//		
	//		mm = m1 * m2;
	//		return mm;
	//	}

	//��ĳ��� �Ǵ� ��İ� ���͸� ��ġ�ϰ� �����ִ� �Լ�
	mat3 multiplyTransposeMatrix(mat3 m1, mat3 m2)
	{
		mat3 mm;

		transposeMatrix(m1);
		transposeMatrix(m2);

		mm = m2 * m1;
		return mm;
	}
	mat4 multiplyTransposeMatrix(mat4 m1, mat4 m2)
	{
		mat4 mm;

		transposeMatrix(m1);
		transposeMatrix(m2);

		mm = m2 * m1;
		return mm;
	}
	vec3 multiplyTransposeMatrix(mat3 m1, vec3 m2)
	{
		vec3 mm;

		transposeMatrix(m1);
		transposeVector(m2);

		mm = m2 * m1;
		return mm;
	}
	vec4 multiplyTransposeMatrix(mat4 m1, vec4 m2)
	{
		vec4 mm;

		transposeMatrix(m1);
		transposeVector(m2);

		mm = m2 * m1;
		return mm;
	}

	//���ͳ��� �Ǵ� ���Ϳ� ����� ��ġ�ϰ� �����ִ� �Լ�
	vec3 multiplyTransposeVector(vec3 m1, vec3 m2)
	{
		vec3 mm;

		transposeVector(m1);
		transposeVector(m2);

		mm = m2 * m1;
		return mm;
	}
	vec3 multiplyTransposeVector(vec3 m1, mat3 m2)
	{
		vec3 mm;

		transposeMatrix(m2);
		transposeVector(m1);

		mm = m2 * m1;
		return mm;
	}
	//vec4 multiplyTransposeVector(vec4 m1, vec4 m2)
	//	{
	//		vec4 mm;
	//			
	//		transposeVector(m1);
	//		transposeVector(m2);
	//
	//		mm = m2 * m1;
	//
	//		return mm;
	//	}
	vec4 multiplyTransposeVector(vec4 m1, mat4 m2)
	{
		vec4 mm;

		transposeVector(m1);
		transposeMatrix(m2);

		mm = m2 * m1;

		return mm;
	}

	//��ĳ����� ���� �Լ�
	mat3 plusMatrix(mat3 m1, mat3 m2)
	{
		mat3 mm;
		mm = m1 + m2;
		return mm;
	}
	mat4 plusMatrix(mat4 m1, mat4 m2)
	{
		mat4 mm;
		mm = m1 + m2;
		return mm;
	}

	//���ͳ����� ���� �Լ�
	vec3 plusVector(vec3 m1, vec3 m2)
	{
		vec3 mm;
		mm = m1 + m2;
		return mm;
	}
	vec4 plusVector(vec4 m1, vec4 m2)
	{
		vec4 mm;
		mm = m1 + m2;
		return mm;
	}

	//��ĳ����� ���� �Լ�
	mat3 minusMatrix(mat3 m1, mat3 m2)
	{
		mat3 mm;
		mm = m1 - m2;
		return mm;
	}
	mat4 minusMatrix(mat4 m1, mat4 m2)
	{
		mat4 mm;
		mm = m1 - m2;
		return mm;
	}

	//���ͳ����� ���� �Լ�
	vec3 minusVector(vec3 m1, vec3 m2)
	{
		vec3 mm;
		mm = m1 - m2;
		return mm;
	}
	vec4 minusVector(vec4 m1, vec4 m2)
	{
		vec4 mm;
		mm = m1 - m2;
		return mm;
	}

	//����� ����� �Լ�
	mat3 multiplyConstantMatrix(mat3 m1, int m2)
	{
		mat3 mm;
		mm = m1 * m2;
		return mm;
	}
	mat4 multiplyConstantMatrix(mat4 m1, int m2)
	{
		mat4 mm;
		mm = m1 * m2;
		return mm;
	}

	//������ ����� �Լ�
	vec3 multiplyConstantVector(vec3 m1, int m2)
	{
		vec3 mm;
		mm = m1 * m2;
		return mm;
	}
	vec4 multiplyConstantVector(vec4 m1, int m2)
	{
		vec4 mm;
		mm = m1 * m2;
		return mm;
	}

	//����� ��� ������ �Լ�
	mat3 divideConstantMatrix(mat3 m1, int m2)
	{
		mat3 mm;
		mm = m1 / m2;
		return mm;
	}
	mat4 divideConstantMatrix(mat4 m1, int m2)
	{
		mat4 mm;
		mm = m1 / m2;
		return mm;
	}

	//������ ��� ������ �Լ�
	vec3 divideConstantVector(vec3 m1, int m2)
	{
		vec3 mm;
		mm = m1 / m2;
		return mm;
	}
	vec4 divideConstantVector(vec4 m1, int m2)
	{
		vec4 mm;
		mm = m1 / m2;
		return mm;
	}
}