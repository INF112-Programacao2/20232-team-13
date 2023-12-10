class Jogador {
    private:
    double _carteira;
    int _vitorias_seguidas;
    std::pair<char,std::string> *_cartas;
    
    public:
    Jogador(int cartas);
    ~Jogador();

    double get_carteira();
    int get_vitorias_seguidas();
    char get_cartas();
    void atualizar_carteira();
    void jogada();
};