//
// Created by panch on 17.05.2020.
//
#include "Sole.hpp"
#include <condition_variable>

struct Task{
    Sole* sole;
    int proc_num; // ���������� ���������
    int k_min, k_max;  // k_min <= �������, �� ������� ����������� ����� <= k_max
    size_t  size;
    std::vector<std::condition_variable>* cond_vars;
    //std::vector<bool>* data_is_ready(p);
    std::vector<std::mutex>* mutexes;
};
std::vector<double> matrix_mult (std::vector<double>& a, std::vector<double>& b){
    std::vector<double> S(4, 0);
    S[0] = a[0]*b[0] + a[1]*b[2];
    S[1] = a[0]*b[1] + a[1]*b[3];
    S[2] = a[2]*b[0] + a[3]*b[2];
    S[3] = a[2]*b[1] + a[3]*b[3];
    return S;
}

void work(Task& task){
    // ������ R �������.  ��� - ����� 13 ��������
    // R = [ a11, a12, a21, 22] - ������ ������ ��������� ������ � ����������
    int rows = task.k_max - task.k_min;
    std::vector<std::vector<double>> Rs(rows, std::vector<double>(4, 0));
    for ( int i = 0; i < rows; ++i){
        if (i == 0){
            Rs[0][0] = task.sole->GetA(i);
            Rs[0][2] = 1;
            continue; // ����� ����� ���. � �� �� ����� � ����� � ����� ����� i ��������ͨ��� � ���Ĩ� �� ����� ����?
        }
        Rs[i][0] = task.sole->GetA(i);
        Rs[i][2] = 1;
        Rs[i][1] = -task.sole->GetB(i)*task.sole->GetC(i-1);
    }
    std::vector<double> S(4, 0); // �� � �������, � ������� ����� ������ ��������� ���������
    // ��� 14 ��������. ����� 2
    S[0] = Rs[rows-1][0];
    S[1] = Rs[rows-1][1];
    S[2] = Rs[rows-1][2];
    S[3] = Rs[rows-1][3];
    for (int i = rows-2; i >= 0; --i){
        S = matrix_mult(S, Rs[i]);
    }

    /*
     * ����� ���������� ����� ��������� S
     * �� ���������� ������������ �������� matrix_mult
     *
     * � ������� ����������� �����-�� ���� ��������� ������� S
     * ������� ������������ �� ���� ��������� ���� R-������ �� ������ �������, ������� ����������� �������� ��������
     * */
    std::vector<double> d(rows, 0);
    // ������ d-���������. ��� - ����� 4.
    // �� ������ ���� ����������, � ������� �� ������ ������� ������� ���� �������� �� ��������
    for (int i = 0; i < rows; ++i){
        S =  matrix_mult(S, Rs[i]); // ���� ����������� �� ������ �����
        d[i] = (S[0] + S[1]) / (S[2] + S[3]);
    }
    /*
     * ������ ������ ������� ���������� ����
     * d[k_max] ����������
     *
     *
     * */
    std::vector<double> l(rows, 0);  // ��� - ����� 6. ������� ����
    //�� ������ ���� ����������, � ������� �� ������ ������� ������� ���� �������� �� ��������
    //l[i] = b[i]/d[i-1]
    double d_max_prev = 1;
    l[0] = task.sole->GetB(task.k_min)/d_max_prev;
    for (int i = 1; i < rows; ++i ){
        l[i] = task.sole->GetB(task.k_min+i)/d[i-1];
    }

    /*������ ��� �������� d � l ��������������, ����� � ������� ���
     * ������ �����. ����� ����� ��� ���������� ��� ��� ����� ��������
     * */
    std::vector<double> d_global(task.sole->GetHeight(),1);
    std::vector<double> l_global(task.sole->GetHeight(),1);
    std::vector<double> y_global(task.sole->GetHeight(), 0);
    std::vector<double> x_global(task.sole->GetHeight(), 0);
    // ������ ��� ��������� ��������
    // � �� ��� ������ ���������������� �����������������������������������������������������������������������������
//    y_global[0] = task.sole->GetFreeVariables()[0]; //������� � ������ ���� ���������� �
//    //�������� ��������� ����, ������� �������� �� ������� �������, ������ ��� �������� ���������������
//    for (size_t i = 1; i <= task.sole->GetHeight(); ++i){
//        y_global[i] = task.sole->GetFreeVariables()[i] - l_global[i]*y_global[i-1];
//    }
//    // �������� ���
//    x_global[task.sole->GetHeight() - 1] = y_global[task.sole->GetHeight() - 1]/d_global[task.sole->GetHeight() - 1];
//    for (size_t i = task.sole->GetHeight() - 2; i > 0; --i  ){
//        x_global[i] = (y_global[i] - task.sole->GetC(i) * x_global[i+1]) / d_global[i];
//    }
//    x_global[0] = (y_global[0] - task.sole->GetC(0) * x_global[1]) / d_global[0];

}