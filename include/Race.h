#ifndef __RACE_H__
#define __RACE_H__

#include <string>

namespace rog {
    class Race {
        protected:
            std::string name;
            std::string description;

            int _str,
                _int,
                _dex,
                _end,
                _cha,
                _per;
        public:
            Race (void);
            Race (std::string & _name, std::string & _description, int a, int b, int c, int d, int e, int f);
            Race (Race & _race);
            virtual ~Race (void);
    
            Race &operator=(Race & _race);

            std::string & getName(void);
            std::string & getDescription(void);

            int getSTR(void);
            int getINT(void);
            int getDEX(void);
            int getEND(void);
            int getCHA(void);
            int getPER(void);
            
            void setName(std::string & _name);
            void setDescription(std::string & _desc);

            void setSTR(int val);
            void setINT(int val);
            void setDEX(int val);
            void setEND(int val);
            void setCHA(int val);
            void setPER(int val);
    };
} /* rog */

#endif /* __RACE_H__ */
