#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include <array>


/**
 * @brief User interface abstraction
 * @details This interface class abstracts the interaction with the user of the game.
 */
class UserInterface
{
public:
    /**
     * @brief Colors for @ref Field
     */
    enum class Color
    {
        RED, /**< color for a red field */
        YELLOW, /**< color for a yellow field */
    };

    /**
     * @brief A field represention
     * @details A Field is after creation empty. If a color is set to the field,
     * there is no way the make the field empty again. Changing a the color of a
     * field is not allowed.
     */
    class Field
    {
    private:
        bool empty;
        Color color;
    public:
        /** The constructor initalizes the Field as empty */
        Field() :
                empty(true), color()
        {
        }

        /**
         * Test if the Field is empty
         * @return true if the Field is empty
         */
        bool isEmpty() const
        {
            return empty;
        }


        /**
         * Getter for the Field color
         * @return Field color
         */
        Color getColor() const
        {
            return color;
        }

        /**
         * Assign a color to the Field
         * @param color the be assigned
         * @return it self
         */
        Field& operator=(Color color)
        {
            empty = false;
            this->color = color;
            return *this;
        }

    };

    /**
     * @brief Exception class to signal a user request to abort the game
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

    /** Datatype to represent the column number */
    typedef unsigned char ColumnType;

    /** Datatype to represent a row of Fields */
    typedef std::array<Field, 7> RowType;

    /** Datatype to represent a grid of Fields */
    typedef std::array<RowType, 6> GridType;

    /**
     * ask the player in which column to place the next disk
     * @param color for the next disk
     * @return column to the place the new disk, zero based
     */
    virtual ColumnType askPlayer(Color color) = 0;

    /**
     * draw the current state of the board
     * @param grid which contains the state of the fields
     */
    virtual void updateBoard(const GridType& grid) = 0;

    /**
     * notify the player who won the game
     * @param color color of the player who won
     */
    virtual void notifyWinner(Color color) = 0;

    /**
     * notify the player that the game ends in a draw
     */
    virtual void notifyDraw() = 0;

 //   virtual void cls()=0;


    virtual ~UserInterface()
    {
    }
};

#endif /* USERINTERFACE_H_ */
