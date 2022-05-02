//
// Created by Azusa on 2022/4/27.
//

#ifndef DOREMICHORD_BACKEND_LRCMODEL_H
#define DOREMICHORD_BACKEND_LRCMODEL_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include "json.h"
#include "base/BaseModel.h"
#include "base/ModelRegister.h"


class LrcModel : public BaseModel {
private:
    static std::vector<std::string> Variable_names;
    static int Model_type;
protected:
    std::string lrc_path;
    std::vector<std::pair<int, std::string> > lrc_list;
public:

    LrcModel();

    static void Init_Model();

    std::string serialization() override;

    bool construction(std::string serialized_text) override;

    ~LrcModel() override;


    template<class T>
    T findAttributeByName(std::string name);

    [[nodiscard]] const std::string &getLrcPath() const;

    void setLrcPath(const std::string &lrcPath);

    const std::vector<std::pair<int, std::string>> &getLrcList();

    void setLrcList(const std::vector<std::pair<int, std::string>> &lrcList);

    void add(int time, std::string lrc);
};


#endif //DOREMICHORD_BACKEND_LRCMODEL_H
