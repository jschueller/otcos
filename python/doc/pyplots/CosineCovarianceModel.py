import openturns as ot
from matplotlib import pyplot as plt
from openturns.viewer import View
import otcos

covarianceModel = otcos.CosineCovarianceModel()
title = str(covarianceModel)[:100]
scale = covarianceModel.getScale()[0]
def f(x):
    return [covarianceModel(x)[0, 0]]
func = ot.PythonFunction(1, 1, f)
func.setDescription(['$tau$', '$cov$'])
cov_graph = func.draw(-8.0, 8.0, 300)
cov_graph.setTitle(title)
fig = plt.figure(figsize=(10, 4))
cov_axis = fig.add_subplot(111)
View(cov_graph, figure=fig, add_legend=False)
