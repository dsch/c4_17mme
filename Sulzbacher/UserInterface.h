#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include <array>

/**
 * @brief (informieren) Benutzeroberfläche Abstraktion (User interface abstraction)
 * @details (näheres) Diese Interface-Klasse abstrahiert die Interaktion mit dem Benutzer des Spiels. (This interface class abstracts the interaction with the user of the game.)
 */
class UserInterface
{
public:
    /**
     * @brief Colors for @ref Field
     */
    enum class Color
    {
        RED, /**< color für ein rotes Feld */
        YELLOW, /**< color für ein gelbes Feld */
    };

    /**
     * @brief Darstellung eines Feldes (A field representation)
     * @details Ein Feld ist nach der Erstellung leer. Wenn eine Farbe auf das Feld gesetzt ist,
     * besteht keine Möglichkeit, das Feld wieder leer zu machen. Ändern der Farbe eines
     * Feldes ist nicht erlaubt.
     * (A Field is after creation empty. If a color is set to the field,
     * there is no way the make the field empty again. Changing a the color of a
     * field is not allowed.)
     */
    class Field
    {
    private:
        bool empty;
        Color color;
    public:
        /** Der Konstruktor initialisiert das Feld als leer. (The constructor initializes the Field as empty) */
        Field() :
                empty(true), color()
        {
        }

        /**
         * Test ob das Feld leer ist (Test if the Field is empty)
         * @return wahr wenn das Feld leer ist (true if the Field is empty)
         */
        bool isEmpty() const
        {
            return empty;
        }

        /**
         * Erzeugt die Feldfarben (Getter for the Field color)
         * @return Field color
         */
        Color getColor() const
        {
            return color;
        }

        /**
         * Weist dem Feld eine Farbe zu (Assign a color to the Field)
         * @param Farbe die zugewiesen wird (color the be assigned)
         * @return sich selbst (it self)
         */
        Field& operator=(Color color)
        {
            empty = false;
            this->color = color;
            return *this;
        }

    };

    /**
     * @brief Ausnahmeklasse, um eine Benutzeranforderung zum Abbruch des Spiels zu signalisieren
     * (Exception class to signal a user request to abort the game)
     */
    class Abort: public std::exception
    {
    public:
        /** @brief returns an explanatory string */
        const char* what() const noexcept
        {
            return "Game aborted by the user";
        }

    };

    /** Datentype der die Spaltennummer angiebt (Datatype to represent the column number) */
    typedef unsigned char ColumnType;

    /**
     * @brief Datentype der die Reihe eines Feldes darstellt (Datatype to represent a row of Fields)
     * @details Der Index 0 bedeueted das ganz linke Feld in einer Zeile (Index 0 means left-most Field in a row)
     */
    typedef std::array<Field, 7> RowType;

    /**
     * @brief Datentype um ein Raster aus Feldern darzustellen (Datatype to represent a grid of Fields)
     * @details Index 0 bedeutet die oberste Zeile des Rasters (Index 0 means top-most Row in the grid)
     */
    typedef std::array<RowType, 6> GridType;

    /**
     * ask the player in which column to place the next disk
     * @param color for the next disk
     * @return column to the place the new disk, zero based
     * @exception Aboard player quits the game
     */
    virtual ColumnType askPlayer(Color color) = 0;

    /**
     * Zeichnet den aktuellen Stand des Spielfeldes (draw the current state of the board)
     * @param grid enhält den Zustand des Feldes (grid which contains the state of the fields)
     */
    virtual void updateBoard(const GridType& grid) = 0;

    /**
     * Benachrichtet den Spieler das dieser gewonnnen hat (notify the player who won the game)
     * @param color color des Spielers wer gewonnen hat (color color of the player who won)
     */
    virtual void notifyWinner(Color color) = 0;

    /**
     * Benachritet die Spieler, dass das Spiel ein unentschieden ist (notify the player that the game ends in a draw)
     */
    virtual void notifyDraw() = 0;

    virtual ~UserInterface()
    {
    }
};

#endif /* USERINTERFACE_H_ */
