/**
 * @file cutbox.h
 * @brief Definição da classe CutBox e seus métodos.
 */

#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe CutBox representa uma caixa/box a ser removida no Sculptor.
 */
class CutBox : public FiguraGeometrica
{
private:
    int x0, x1, y0, y1, z0, z1;

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
     * @brief Método responsável por remover a caixa/box no Sculptor.
     * @param t Referência para um objeto Sculptor onde a caixa será removida.
     */
    void draw(Sculptor &t);

    /**
     * @brief Construtor parametrizado da classe CutBox.
     * @param v Vetor contendo as informações da caixa a ser removida (x, x1, y, y1, z, z1).
     */
    CutBox(std::vector<std::string> v);
};

#endif // CUTBOX_H
