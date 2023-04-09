#ifndef TIPKR_FOOD_H
#define TIPKR_FOOD_H



class Food {
public:
    Food(); // конструктор класса
    void Init(); // инициализация еды
    void Render(); // отрисовка еды
    int GetX(); // получить координату X еды
    int GetY(); // получить координату Y еды
    void Randomize(); // рандомизировать координаты еды
    void Spawn( int screenWidth, int screenHeight); // отображение еды на игровом поле
private:
    int position; // координаты еды на игровом поле
};



#endif //TIPKR_FOOD_H
