class Jogos{
    private:
    double _odds;
    char *crupie;
    char *baralho;

    public:
    Jogos();
    ~Jogos();
    double get_odds();
    char get_crupie();
    char get_baralho();
    void set_odds(double odds);
    void apostar(double aposta);
    virtual void jogar()=0;
    virtual void vitoria()=0;
    void embaralhar();
};