class Jogador {
    private:
    double _carteira;
    int _vitorias_seguidas;
    char *_cartas;
    
    public:
    Jogador();
    ~Jogador();
    double get_carteira();
    int get_vitorias_seguidas();
    char get_cartas();
    void atualizar_carteira();
    void jogada();
};