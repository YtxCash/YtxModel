#ifndef SQLITESTAKEHOLDER_H
#define SQLITESTAKEHOLDER_H

#include "sqlite.h"

class SqliteStakeholder final : public Sqlite {
    Q_OBJECT

public:
    SqliteStakeholder(CInfo& info, QObject* parent = nullptr);

protected:
    // tree
    void ReadNode(Node* node, const QSqlQuery& query) override;
    void WriteNode(Node* node, QSqlQuery& query) override;

    QString BuildTreeQS() const override;
    QString InsertNodeQS() const override;
    QString RemoveNodeSecondQS() const override;
    QString InternalReferenceQS() const override;
    QString ExternalReferenceQS() const override;
    QString LeafTotalQS() const override { return QString(); }

    // table
    void ReadTrans(Trans* trans, const QSqlQuery& query) override;
    void WriteTransShadow(TransShadow* trans_shadow, QSqlQuery& query) override;
    void UpdateProductReference(int old_node_id, int new_node_id) override;

    QString RRemoveNodeQS() const override;
    QString BuildTransShadowListRangQS(QStringList& list) const override;
    QString BuildTransShadowListQS() const override;
    QString InsertTransShadowQS() const override;
    QString RelatedNodeTransQS() const override;
    QString RReplaceNodeQS() const override;
    QString RUpdateProductReferenceQS() const override;
};

#endif // SQLITESTAKEHOLDER_H
