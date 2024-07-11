#ifndef READFILE_H
#define READFILE_H
#include "figurageometrica.h"
#include "sculptor.h"
#include <fstream>
#include <string>
#include <vector>

/**
 * @brief A classe ReadFile é responsável por ler um arquivo e criar desenhos em
 * um Sculptor.
 */
class ReadFile {
private:
  std::ifstream
      fin; /// Stream de entrada para ler o arquivo de instruções do desenho.
  std::string line;    /// Linha lida do arquivo.
  std::string palavra; ///< Palavra atual sendo processada.
public:
  /**
   * @brief Construtor padrão da classe ReadFile.
   */
  ReadFile();
  /**
   * @brief Método para ler um arquivo e criar desenhos em um Sculptor.
   * @param desenho Vetor de ponteiros para FiguraGeometrica onde os desenhos
   * serão armazenados.
   * @param t Ponteiro para um objeto Sculptor onde os desenhos serão criados.
   * @param filename Nome do arquivo a ser lido.
   */
  void read(std::vector<FiguraGeometrica *> &desenho, Sculptor *&t,
            const char *filename);
  /**
   * @brief Destrutor da classe ReadFile.
   */
  ~ReadFile();
};

#endif // READFILE_H