class Particule {
protected:
    int         lifeTime;
    int         age;
    int         size;
    vec3        position;
    vec3        speed;
public:
    Particule();
    Particule(int lifeTime, int size, vec3 pos, vec3 speed);

    void Render();
    bool isALive();

};
