#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"

/**
 * @brief A classe CutBox representa a remoção de uma caixa em um Sculptor.
 */
class CutBox : public FiguraGeometrica{
private:
    int x,x1,y,y1,z,z1; /// Coordenadas da caixa a ser removida no Sculptor.
public:
    /**
     * @brief Construtor padrão da classe CutBox.
     */
    CutBox();
    /**
    * @brief Destrutor da classe CutBox.
    */
    virtual ~CutBox();
    /**
     * @brief Método responsável por remover a caixa no Sculptor.
     * @param t Referência para um objeto Sculptor onde a caixa será removida.
     */
    void draw(Sculptor &t);
    /**
     * @brief Construtor parametrizado da classe CutBox.
     * @param v Vetor contendo as informações da caixa a ser removida (x, x1, y, y1, z, z1).
     */
    CutBox(std::vector <std::string> v);
};

#endif // CUTBOX_H