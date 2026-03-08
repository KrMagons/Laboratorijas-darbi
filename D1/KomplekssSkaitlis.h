#ifndef KOMPLEKSSSKAITLIS_H_INCLUDED
#define KOMPLEKSSSKAITLIS_H_INCLUDED

class KomplekssSkaitlis{
private:
    double a;
    double b;
public:
    KomplekssSkaitlis(double a, double b);

    ~KomplekssSkaitlis();

    void pieskaitit(double c, double d);

    void reizinat(double c, double d);

    void drukat();
};

#endif // KOMPLEKSSSKAITLIS_H_INCLUDED
