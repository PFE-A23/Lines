#ifndef __Scene_h_
#define __Scene_h_

#include "Frame.h"
#include "drwCommand.h"
#include <QObject>
#include <QReadWriteLock>
#include <vector>

class drwGLRenderer;
class Box2d;

class Scene : public QObject {

  Q_OBJECT

public:
  Scene(QObject *parent = 0);
  ~Scene();

  void SetRenderer(drwGLRenderer *r) { m_renderer = r; }
  void Clear();
  void EmitStateCommand();

  void DrawFrame(int frame, drwDrawingContext &context);

  int AddNodeToFrame(Node *node, int frame);
  Node *GetNodeById(int frame, unsigned Id);

  // Lock a node in a frame for writing
  Node *LockNode(int frameIndex, int nodeIndex);
  void UnlockNode(int frameIndex, int nodeIndex);

  void SetNumberOfFrames(int nbFrames);
  int GetNumberOfFrames() { return m_frames.size(); }
  void InsertFrame(int beforeThisFrame);

  // used by other classes to mark end of modification and notify clients they
  // can re-render
  void MarkModified();
  void MarkModified(int frame, Box2d &rect);

signals:

  void NumberOfFramesChanged(int);
  void CommandExecuted(drwCommand::s_ptr command);

protected:
  drwGLRenderer *m_renderer;
  QReadWriteLock m_framesLock;
  typedef std::vector<Frame *> FrameCont;
  FrameCont m_frames;
};

#endif
