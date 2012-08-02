#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H


class Displayable
{
    public:
        Displayable();
        virtual ~Displayable();
        unsigned int GetLayer();
        void SetLayer(unsigned int val);
        sf::Drawable GetDrawable();
        void SetDrawable(sf::Drawable val);
    protected:
    private:
        unsigned int myLayer;
        sf::Drawable myDrawable;
};

#endif // DISPLAYABLE_H
